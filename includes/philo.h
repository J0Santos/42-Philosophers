/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:02:52 by josantos          #+#    #+#             */
/*   Updated: 2021/11/13 17:48:25 by josantos         ###   ########.fr       */
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

# define MALLOC_ERROR 11
# define MUTEX_ERROR 12
# define THREAD_ERROR 13
# define ARGS_ERROR 14

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
	t_mutex		*print;
	pthread_t	thread;
}	t_control;

typedef struct s_philo
{
	t_control		*data;
	int				id;
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

void		error_message(int type, char *message);
int			check_values(t_control *data);

/*
*Init Functions
*/

t_control	*init_data(int argc, char **argv);
void		init_mutex(t_control *data);

#endif
