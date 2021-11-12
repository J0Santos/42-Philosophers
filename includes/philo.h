/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:02:52 by josantos          #+#    #+#             */
/*   Updated: 2021/11/12 16:07:53 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define TRUE 1
# define FALSE 0

typedef long long	t_time;

typedef pthread_mutex_t t_mutex;

typedef int	t_bool;

typedef enum e_state
{
	Sleeping,
	Eating,
	Thinking,
}	t_state;

typedef struct s_control
{
	long long	n_philos;
	t_time		time2die;
	t_time		time2eat;
	t_time		time2sleep;
	long long	eat_limit;
	t_mutex		*fork;
	t_mutex		print;
}	t_control;

typedef struct s_philo
{
	t_control		*data;
	int				id;
	pthread_t		thread;
	t_state			state;
	t_time			last_meal;
	int				times_ate;
	t_bool			alive;
}	t_philo;

/*
 * Util functions
 */

size_t		ft_strlen(const char *str);
long long	ft_atoll(char *str);
int			is_digit(char *str);
int			is_int(char	*str);
int			is_pos(char *str);

/*
 * main functions
 */

void		argument_check(int argc, char **argv);
t_control	*init_data(int argc, char **argv);
void		error_message(int type, char *message);

#endif
