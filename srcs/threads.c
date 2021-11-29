/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:07:44 by josantos          #+#    #+#             */
/*   Updated: 2021/11/29 16:15:22 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*one_philo_routine(void *arg)
{
	t_philo	*philo;
	int test;

	philo = (t_philo *)arg;
	printf("%dms\tPhilosopher %d was born\n", get_time(philo), philo->id);
	printf("%dms\t%d %s", get_time(philo), philo->id, FORK);
	test = current_time() - philo->last_action;
	printf ("time:%d, la:%d, %d\n", current_time(), philo->last_action, test);
	if (ft_wait(philo, philo->info->time2die))
		printf("%dms\t%d %s", get_time(philo), philo->id, DEAD);
	else
		printf("shit...");
	return (0);
}

void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	printf("%dms\tPhilosopher %d was born\n", philo->time, philo->id);
	while (philo->info->dead == 0)
	{
		prepare4meal(philo);
		//check_dead(philo);
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