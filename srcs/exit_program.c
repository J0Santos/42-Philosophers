/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:03:24 by josantos          #+#    #+#             */
/*   Updated: 2021/11/23 15:26:42 by josantos         ###   ########.fr       */
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

void	exit_program(t_info *info)
{
	destroy_mutexes(info);
//	free(data->fork);
//	free(data->thread);
	free(info);
//	free(philo);
//	if (type == THREAD_ERROR)
//		error_message(THREAD_ERROR, "Thread Error\n");
//	else
		exit(EXIT_SUCCESS);
}