/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:58:03 by josantos          #+#    #+#             */
/*   Updated: 2021/12/02 14:58:51 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_info *info)
{
	int		i;

	info->philo = (t_philo *)malloc(sizeof(t_philo) * info->num_philos);
	if (!info->philo)
		return (free_space_1(info, 2.0));
	i = 0;
	while (i < info->num_philos)
	{
		info->philo[i].id = i + 1;
		info->philo[i].has_forks = false;
		info->philo[i].meal_count = 0;
		info->philo[i].last_meal = info->start_time;
		info->philo[i].info = info;
		info->philo[i].last_action = info->start_time;
		i++;
	}
	return (SUCCESS);
}

int	init_forks(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philos)
	{
		info->fork->used = false;
		if (pthread_mutex_init(&info->fork[i++].mutex, NULL) != 0)
		{
			while (i >= 0)
			{
				pthread_mutex_destroy(&info->fork[--i].mutex);
			}
			return (free_space_1(info, 1.5));
		}
	}
	return (SUCCESS);
}

int	init_mutexes(t_info *info)
{
	info->fork = (t_fork *)malloc(sizeof(t_fork) * info->num_philos);
	if (!info->fork)
	{
		free(info);
		return (free_space_1(info, 1.0));
	}
	if (pthread_mutex_init(&info->print, NULL) != 0)
		return (free_space_1(info, 1.3));
	if (init_forks(info))
		return(FAILURE);
	return (SUCCESS);
}

int	init_data(t_info *info, int argc, char **argv)
{
	info->num_philos = ft_atoll(argv[1]);
	info->time2die = ft_atoll(argv[2]);
	info->time2eat = ft_atoll(argv[3]);
	info->time2sleep = ft_atoll(argv[4]);
	if (argc == 6)
		info->max_meals = ft_atoll(argv[5]);
	else
		info->max_meals = -1;
	info->dead = 0;
	if (check_values(info))
		return (error_message(ARGS_ERROR, "Please insert values again\n"));
	if (init_mutexes(info))
		return (FAILURE);
	info->start_time = current_time();
	if (init_philo(info))
		return (FAILURE);
	return (SUCCESS);
}