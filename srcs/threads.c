/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:07:44 by josantos          #+#    #+#             */
/*   Updated: 2021/11/25 17:50:20 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	printf("%dms\tPhilosopher %d was born\n", philo->curr_time, philo->id);
	while (philo->info->dead == 0)
	{
		get_forks(philo);
	}
	return (0);
}

void	thread_create(t_info *info)
{
	int i;

	i = 0;
	info->thread = (pthread_t *)malloc(sizeof(pthread_t) * info->num_philos);
	if (!info->thread)
		exit_program(info, MALLOC_ERROR);
	while (i < info->num_philos)
	{
		if (pthread_create(&(info->thread[i]), NULL, &routine, 
								&info->philo[i]))
			error_message(THREAD_ERROR, "Thread error - create\n");
		i++;
	}
	i = 0;
	while (i < info->num_philos)
	{
		if (pthread_join(info->thread[i], NULL))
			error_message(THREAD_ERROR, "Thread error - join\n");
		i++;
	}
}