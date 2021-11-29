/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:14:26 by josantos          #+#    #+#             */
/*   Updated: 2021/11/29 16:14:37 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_wait(t_philo *philo, int action)
{
	while (action > (current_time() - philo->last_action))
	{
		if (check_dead(philo))
			return (1);
	}
	return (0);
}

int	current_time(void)
{
	struct timeval	time;
	
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	get_time(t_philo *philo)
{
	return (current_time() - philo->info->start_time);
}