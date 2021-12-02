/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:39:46 by josantos          #+#    #+#             */
/*   Updated: 2021/12/02 18:02:54 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
 
void	get_forks(t_philo *philo, int first, int second)
{
	pthread_mutex_lock(&philo->info->fork[first].mutex);
	pthread_mutex_lock(&philo->info->fork[second].mutex);
	if (!philo->info->dead && philo->info->fork[first].used == false
		&& philo->info->fork[second].used == false)
	{
		philo->info->fork[first].used = true;
		philo->info->fork[second].used = true;
		philo->has_forks = true;
		ft_print(philo, FORK);
		ft_print(philo, FORK);
	}	
	pthread_mutex_unlock(&philo->info->fork[first].mutex);
	pthread_mutex_unlock(&philo->info->fork[second].mutex);
}

void	philo_eat(t_philo *philo, int first, int second)
{
	printf("b %d\n", philo->id);
		ft_print(philo, EAT);
		ft_wait(philo, philo->info->time2eat);
		philo->last_meal = philo->last_action;
		philo->meal_count += 1;
		philo->info->fork[first].used = false;
		philo->info->fork[second].used = false;
		philo->has_forks = false;
}

void	philo_sleep(t_philo *philo)
{
	ft_print(philo, SLEEP);
	ft_wait(philo, philo->info->time2sleep);
}