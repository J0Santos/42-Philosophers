/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:03:24 by josantos          #+#    #+#             */
/*   Updated: 2021/11/24 17:42:24 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutexes(t_info *info)
{
	int i;

	i = 0;
	while (i < info->num_philos)
		pthread_mutex_destroy(&info->fork[i++]);
	pthread_mutex_destroy(&info->print);
	free(info->fork);
}

void	exit_program(t_info *info, int type)
{
	// if (type != FAILURE_INFO)
	// {
	// 	destroy_mutexes(info);
	// 	free(info->philo);
	// }
	free(info);
//	free(data->thread);
//	if (type == THREAD_ERROR)
//		error_message(THREAD_ERROR, "Thread Error\n");
//	else
	if (type == FAILURE_INFO || type == FAILURE_PHILO)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}