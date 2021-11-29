/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:39:46 by josantos          #+#    #+#             */
/*   Updated: 2021/11/29 16:17:58 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead(t_philo *philo)
{
	if (philo->info->time2die < current_time() - philo->last_meal)
	{
		philo->info->dead = 1;
		return (1);
	}
	else
		return (0);
}

void	prepare4meal(t_philo *philo)
{
	if (philo->info->fork[philo->id - 1].id == 0 && philo->info->fork[philo->id].id == 0)
	{
		pthread_mutex_lock(&philo->info->fork[philo->id - 1].mutex);
		pthread_mutex_lock(&philo->info->fork[philo->id].mutex);
		philo->info->fork[philo->id - 1].id = philo->id;
		philo->info->fork[philo->id].id = philo->id;
		printf("%dms\t%d %s", philo->time, philo->id, FORK);
		printf("%dms\t%d %s", philo->time, philo->id, FORK);
		printf("%dms\t%d %s", philo->time, philo->id, EAT);
		//ft_wait(philo, philo->info->time2eat);
		
	}
	
}
/*
void	check_dead(t_philo *philo)
{
	if (philo->info->time2die < )
}
*/
