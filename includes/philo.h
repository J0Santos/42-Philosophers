/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:02:52 by josantos          #+#    #+#             */
/*   Updated: 2021/11/27 00:19:21 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>
# include <unistd.h>
# include "color.h"

/* Types */

# define SUCCESS 0
# define FAILURE 1
# define ARGS_ERROR 10
# define MALLOC_ERROR 11
# define MUTEX_ERROR 12
# define THREAD_ERROR 13

/* Print State */

# define FORK "has taken a fork\n"
# define EAT "is eating\n"
# define SLEEP "is sleeping\n"
# define THINK "is thinking\n"
# define DEAD "died\n"

typedef pthread_mutex_t t_mutex;

typedef struct s_fork
{
	t_mutex	mutex;
	int		id;
}	t_fork;

typedef struct s_philo
{
	int					id;
	int					meal_count;
	int					last_meal;
	int					last_action;
	int					time;
	struct s_info		*info;
}	t_philo;

typedef struct s_info
{
	int					time2die;
	int					time2eat;
	int					time2sleep;
	int					num_philos;
	int					max_meals;
	int					start_time;
	bool				dead;
	t_fork				*fork;
	t_mutex				print;
	pthread_t			*thread;
	t_philo				*philo;
}	t_info;

/* Init Functions */

int			init_data(t_info *info, int argc, char **argv);
int			init_mutexes(t_info *info);
int			init_philo(t_info *info);

/* Checker Functions */

int			check_values(t_info *info);
int			check_args(int argc, char **argv);

/* Program Termination Functions */

int			error_message(int type, char *message);
int			free_space_1(t_info *info, float phase);
int			free_space_2(t_info *info, float phase);
void		destroy_mutexes(t_info *info);
void		finish_program(t_info *info);

/* Threads Functions */

int			thread_create(t_info *info);

/* Routine Functions */

int			one_philo(t_info *info);
void		prepare4meal(t_philo *philo);
int			ft_wait(t_philo *philo, int time);

/* Time functions */

int			get_time(t_philo *philo);
int			current_time();

/* Util Functions */

size_t		ft_strlen(const char *str);
long long	ft_atoll(char *str);
int			is_digit(char *str);
int			is_int(char	*str);
int			is_pos(char *str);

#endif
