#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#
#                                                                           #
#   Makefile                                                                #
#    josantos                                                               #
#                                                                           #
#    Options: (make FLAG=1/0)                                               #
#     DEBUG -> Compiles with "-g" flag                                      #
#     SANITIZER -> Compiles with "-g" and "-fsanitize=address" flags        #
#     NO_FLAGS -> Compiles without "-Wall", "-Wextra" and "-Werror" flags   #
#                                                                           #
#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#
#######  ~~~   Initial variable setup   ~~~  #######
NAME := philo
SRCS_DIR := ./srcs
OBJS_DIR := ./objs
SRCS := $(wildcard $(SRCS_DIR)/*/*.c) $(wildcard $(SRCS_DIR)/*.c)
OBJS := $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
DPND := $(OBJS:.o=.d)
INCLUDES := -Iincludes
COMPILER := gcc
WWW_FLAGS := -Wall -Wextra -Werror
OPT_FLAGS := -O3
INC_FLAGS := -MD
TMP_FILE := Makefile.tmp
####################################################
#######  ~~~   Compilation setup   ~~~  #######
# Ensures that TMP_FILE exists before calling awk
$(shell touch $(TMP_FILE))
# Reads DEBUG option from TMP_FILE if user hasn't provided it
ifndef DEBUG
	ifeq ($(shell awk 'NR==1 {print $$3}' $(TMP_FILE)),1)
		DEBUG = 1
	else
		DEBUG = 0
	endif
else
	PRE_EXECUTE = clean
endif
# Reads SANITIZER option from TMP_FILE if user hasn't provided it
ifndef SANITIZER
	ifeq ($(shell awk 'NR==2 {print $$3}' $(TMP_FILE)),1)
		SANITIZER = 1
	else
		SANITIZER = 0
	endif
else
	PRE_EXECUTE = clean
endif
# Reads NO_FLAGS option from TMP_FILE if user hasn't provided it
ifndef NO_FLAGS
	ifeq ($(shell awk 'NR==3 {print $$3}' $(TMP_FILE)),1)
		NO_FLAGS = 1
	else
		NO_FLAGS = 0
	endif
else
	PRE_EXECUTE = clean
endif
# Configure DEBUG
ifeq ($(DEBUG),1)
	DEBUG_FLAGS = -g
	OPT_FLAGS =
endif
# Configure SANITIZER
ifeq ($(SANITIZER),1)
	DEBUG_FLAGS = -g -fsanitize=address
	OPT_FLAGS =
endif
# Configure NO_FLAGS
ifeq ($(NO_FLAGS),1)
	WWW_FLAGS =
endif
$(shell echo "DEBUG = $(DEBUG)\nSANITIZER = $(SANITIZER)\nNO_FLAGS = $(NO_FLAGS)" > $(TMP_FILE))
ifeq ($(shell uname -s),Linux)
	DEBUGGER = gdb
	OS = 2
endif
ifeq ($(shell uname -s),Darwin)
	DEBUGGER = lldb
	OS = 1
endif
###############################################
#######  ~~~   Rules and commands setup   ~~~  #######
.PHONY: all
all: $(PRE_EXECUTE)
	@printf "[\e[1;34mPreparing objects\e[0m]\n\n"
	@$(MAKE) $(NAME) --no-print-directory
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(shell [ ! -d $(@D) ] && mkdir -p $(@D))
	$(COMPILER) $(WWW_FLAGS) $(OPT_FLAGS) $(INC_FLAGS) $(DEBUG_FLAGS) -pthread $(INCLUDES) -DOS=$(OS) -c -o $@ $<
$(NAME): $(OBJS)
	@printf "\n[\e[1;34mCompiling $(NAME)\e[0m]\n\n"
	$(COMPILER) $(WWW_FLAGS) $(OPT_FLAGS) $(INC_FLAGS) $(DEBUG_FLAGS) -pthread $(INCLUDES) $(OBJS) -DOS=$(OS) -o $(NAME)
	@printf "\n[\e[0;32mCompilation done. $(NAME) ready.\e[0m]\n"
.PHONY: clean
clean:
	@printf "[\e[1;33mCleaning\e[0m]\n\n"
	rm -f $(OBJS)
	rm -f $(DPND)
	@$(shell if [[ "$(shell test -d $(OBJS_DIR) && find $(OBJS_DIR) -type f | wc -l)" -eq 0 ]]; then rm -rf $(OBJS_DIR); fi;)
.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	rm -f $(TMP_FILE)
.PHONY: re
re:
	@$(MAKE) fclean --no-print-directory
	@printf "\n"
	@$(MAKE) all --no-print-directory
.PHONY: debug
debug:
	@$(MAKE) all DEBUG=1 --no-print-directory
	@printf "\n[\e[1;34mStarting $(DEBUGGER)\e[0m]\n\n"
	$(DEBUGGER) ./$(NAME)
-include $(DPND)
######################################################
