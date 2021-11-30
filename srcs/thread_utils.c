/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 19:27:03 by josantos          #+#    #+#             */
/*   Updated: 2021/11/30 20:49:29 by josantos         ###   ########.fr       */
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

void	ft_print(t_philo *philo, char *state)
{
	pthread_mutex_lock(&philo->info->print);
	if (philo->info->dead == 1)
	{
		printf("%dms\t%d %s", get_time(philo), philo->id, state);
		return ;
	}
	else
		printf("%dms\t%d %s", get_time(philo), philo->id, state);
	if (state[0] != 'h')
		philo->last_action = current_time();
	pthread_mutex_unlock(&philo->info->print);
}