/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:39:46 by josantos          #+#    #+#             */
/*   Updated: 2021/11/27 00:27:46 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



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
