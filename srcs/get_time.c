/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:14:26 by josantos          #+#    #+#             */
/*   Updated: 2021/11/27 00:27:17 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
int	ft_wait(t_philo *philo, int time)
{
	int	i;
	int diff;
	
	i = get_time();
	while (get_time() - i <= time)
	{
		diff = philo->last_meal;
		if (diff > philo->info->time2die)
		{
			pthread_mutex_lock(&philo->info->print);
			philo->info->dead = 1;
			break ;
		}
	}
	return (0);
}
*/
int	current_time(void)
{
	struct timeval	time;
	
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	get_time(t_philo *philo)
{
	return (philo->last_action - philo->info->start_time);
}