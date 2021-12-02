/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 19:27:03 by josantos          #+#    #+#             */
/*   Updated: 2021/12/02 18:51:55 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_forks(t_philo *philo, int *first, int *second)
{
	*first = philo->id % philo->info->num_philos;
	*second = philo->id - 1 % philo->info->num_philos;
}

int	check_dead(t_philo *philo)
{
	if (philo->info->time2die < current_time() - philo->last_meal)
	{
		pthread_mutex_lock(&philo->info->print);
		if (philo->info->dead == false)
		{
			philo->info->dead = true;
			printf(""RED"%dms\t%d %s"RESET"", get_time(philo), philo->id, DEAD);
		}
		pthread_mutex_unlock(&philo->info->print);
	}
	if (philo->info->dead == true)
		return (1);
	return (0);
}

void	ft_print(t_philo *philo, char *state)
{
	pthread_mutex_lock(&philo->info->print);
	if (philo->info->dead == true)
	{
		pthread_mutex_unlock(&philo->info->print);
		return ;
	}
	printf("%dms\t%d %s", get_time(philo), philo->id, state);
	if (state[0] != 'h')
		philo->last_action = current_time();
	pthread_mutex_unlock(&philo->info->print);
}