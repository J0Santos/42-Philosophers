/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:02:52 by josantos          #+#    #+#             */
/*   Updated: 2021/11/24 17:21:44 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>

/* Types */

# define SUCCESS 1
# define FAILURE_INFO 2
# define FAILURE_PHILO 3
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

typedef struct s_philo
{
	int					id;
	int					meal_count;
	int					last_meal;
	pthread_t			thread;
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
	t_mutex				*fork;
	t_mutex				print;
	bool				dead;
	t_philo				*philo;
}	t_info;

/* Init Functions */

t_info		*init_data(int argc, char **argv);
void		init_mutexes(t_info *info);
void		init_philo(t_info *info);

/* Checker Functions */

int			check_values(t_info *info);
void		check_args(int argc, char **argv);

/* Program Termination Functions */

void		error_message(int type, char *message);
void		exit_program(t_info *info, int type);

/* Time function */

int			get_time(void);

/* Util Functions */

size_t		ft_strlen(const char *str);
long long	ft_atoll(char *str);
int			is_digit(char *str);
int			is_int(char	*str);
int			is_pos(char *str);

#endif
