/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:02:52 by josantos          #+#    #+#             */
/*   Updated: 2021/11/16 12:31:51 by josantos         ###   ########.fr       */
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

# define ERROR 10
# define MALLOC_ERROR 11
# define MUTEX_ERROR 12
# define THREAD_ERROR 13
# define ARGS_ERROR 14
# define FINISHED 15

typedef long long	t_time;

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
	pthread_mutex_t		*fork;
	pthread_mutex_t		*print;
	pthread_t	*thread;
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
 * Util
 */

size_t		ft_strlen(const char *str);
long long	ft_atoll(char *str);
int			is_digit(char *str);
int			is_int(char	*str);
int			is_pos(char *str);

/*
 * Main
 */

void		argument_check(int argc, char **argv);
void		error_message(int type, char *message);
int			check_values(t_control *data);
void		exit_program(t_control *data, t_philo *philo, int type);
void		destroy_mutexes(t_control *data);

/*
* Threads
*/

void		malloc_thread(t_control *data);
void		init_thread(t_control *data, t_philo *philo);
void		*routine(void *philo);

/*
*Init
*/

t_control	*init_data(int argc, char **argv);
void		init_mutex(t_control *data);
t_philo		*init_philo(t_control *data);


#endif
