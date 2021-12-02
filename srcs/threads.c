/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:07:44 by josantos          #+#    #+#             */
/*   Updated: 2021/12/02 18:48:48 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*one_philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("%dms\t%d %s", get_time(philo), philo->id, FORK);
	ft_wait(philo, philo->info->time2die);
	printf("%dms\t%d %s", get_time(philo), philo->id, DEAD);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		first;
	int		second;

	philo = (t_philo *)arg;
	create_forks(philo, &first, &second);
	while (philo->info->dead == false)
	{
		ft_print(philo, THINK);
		while (philo->has_forks == false && !philo->info->dead)
		{
			if (philo->id % 2 == 0)
				get_forks(philo, first, second);
			else
				get_forks(philo, second, first);
		}
		philo_eat(philo, first, second);
		if (philo->meal_count == philo->info->max_meals)
			break ;
		philo_sleep(philo);
	}
	return (0);
}

int	one_philo(t_info *info)
{
	int i;

	i = 0;
	if (pthread_create(&(info->thread[i]), NULL, &one_philo_routine, 
							&info->philo[i]))
		return (free_space_1(info, 3.0));
	if (pthread_join(info->thread[i], NULL))
		return (free_space_1(info, 3.5));
	return (SUCCESS);
}

int	thread_create(t_info *info)
{
	int i;

	info->thread = (pthread_t *)malloc(sizeof(pthread_t) * info->num_philos);
	if (!info->thread)
		return (free_space_1(info, 2.5));
	if (info->num_philos == 1)
	{
		if (one_philo(info))
			return (FAILURE);
		return (SUCCESS);
	}
	i = -1;
	while (++i < info->num_philos)
		if (pthread_create(&(info->thread[i]), NULL, &routine, 
								&info->philo[i]))
			return (free_space_1(info, 3.0));
	i = 0;
	while (i < info->num_philos)
		if (pthread_join(info->thread[i++], NULL))
			return (free_space_1(info, 3.5));
	return (SUCCESS);
}