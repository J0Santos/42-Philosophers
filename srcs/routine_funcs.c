/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:39:46 by josantos          #+#    #+#             */
/*   Updated: 2021/11/25 17:54:18 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_forks(t_philo *philo)
{
	if (philo->info->fork[philo->id - 1].id == 0 && philo->info->fork[philo->id].id == 0)
	{
		pthread_mutex_lock(philo->info->fork[philo->id - 1].mutex);
		pthread_mutex_lock(philo->info->fork[philo->id].mutex);
		printf("%dms\t%d %s", philo->curr_time, philo->id, FORK);
		printf("%dms\t%d %s", philo->curr_time, philo->id, FORK);
		printf("%dms\t%d %s", philo->curr_time, philo->id, EAT);
	}
	
}