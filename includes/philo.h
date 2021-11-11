/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:39:19 by josantos          #+#    #+#             */
/*   Updated: 2021/11/10 17:00:44 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

typedef long long t_time

typedef struct s_philo
{
	int				number;
	t_time			time2die;
	t_time			time2eat;
	t_time			time2sleep;
	int				times_ate;
	pthread_t	thread;
}	t_philo;

typedef struct s_data
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	int				eat_limit;
}	t_data;

/*
 * Util functions
 */

size_t	ft_strlen(const char *str);
long long	ft_atoll(char *str);
int		is_digit(char *str);
int		is_int(char	*str);
int		is_pos(char *str);

/*
 * main functions
 */

void	argument_check(int argc, char **argv);
void	init_data(int argc, char **argv);
void	error_message(int type, char *message);

#endif
