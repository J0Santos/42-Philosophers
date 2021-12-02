/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:44:18 by josantos          #+#    #+#             */
/*   Updated: 2021/12/02 19:32:27 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_space_2(t_info *info, float phase)
{
	free(info->fork);
	free(info);
	if (phase >= 2.0 && phase < 3.0)
	{
		if (phase == 2.0)
			return (error_message(MALLOC_ERROR, "Malloc Error - philo\n"));
		else if (phase == 2.5)
		{
			free(info->philo);
			return (error_message(MALLOC_ERROR, "Malloc Error - thread\n"));
		}	
	}
	if (phase >= 3.0)
	{
		free(info->philo);
		free(info->thread);
		if (phase == 3.0)
			return (error_message(THREAD_ERROR, "Thread Error - create\n"));
		else
			return (error_message(THREAD_ERROR, "Thread Error - join\n"));
	}
	return (FAILURE);
}

int	free_space_1(t_info *info, float phase)
{
	int	error;

	if (phase >= 1.0 && phase < 2.0)
	{
		if (phase == 1.0)
			return (error_message(MALLOC_ERROR, "Malloc Error - fork\n"));
		free(info->fork);
		if (phase == 1.3)
			return (error_message(MUTEX_ERROR, "Mutex Error - print\n"));
		if (phase == 1.5)
			return (error_message(MUTEX_ERROR, "Mutex Error - fork\n"));
	}
	error = free_space_2(info, phase);
	return (error);
}

void	finish_program(t_info *info)
{
	free(info->thread);
	free(info->philo);
	free(info->fork);
	free(info);
}
