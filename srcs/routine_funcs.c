/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:39:46 by josantos          #+#    #+#             */
/*   Updated: 2021/11/30 21:05:35 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	grab_forks(t_philo *philo, t_fork *right_fork, t_fork *left_fork)
{
	pthread_mutex_lock(&philo->info->fork[right_fork].mutex);
	pthread_mutex_lock(&philo->info->fork[left_fork].mutex);
	
	return (0);
}

int	philo_eat(t_philo *philo)
{
	ft_print(philo, EAT);
	if (ft_wait(philo, philo->info->time2eat))
		return (1);
	philo->last_meal = philo->last_action;
	philo->info->fork[philo->id - 1].id = 0;
	pthread_mutex_unlock(&philo->info->fork[philo->id - 1].mutex);
	philo->info->fork[philo->id].id = 0;
	pthread_mutex_unlock(&philo->info->fork[philo->id].mutex);
	philo->has_forks = 0;
	return (0);
}

int	philo_sleep(t_philo *philo)
{
	ft_print(philo, SLEEP);
	if (ft_wait(philo, philo->info->time2sleep))
		return (1);
	return (0);
}

int	prepare4meal(t_philo *philo)
{	
	int		thinking;
	t_fork	*right_fork;
	t_fork	*left_fork;
	
	right_fork = &philo->info->fork[philo->id];
	left_fork = &philo->info->fork[philo->id - 1];
	thinking = 0;
	while (philo->has_forks == 0)
	{
		if (grab_forks(philo, left_fork, right_fork))
		{
			philo->has_forks = 1;
			return (0);
		}
		else if (philo->has_forks == 0 && thinking == 0)
		{
			ft_print(philo, THINK);
			thinking = 1;
		}
		if (check_dead(philo))
			return (1);
	}
	return (0);
}