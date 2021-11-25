/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:58:03 by josantos          #+#    #+#             */
/*   Updated: 2021/11/25 17:49:00 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_info *info)
{
	int		i;
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * info->num_philos);
	if (!philo)
		error_message(MALLOC_ERROR, "Malloc error - philo\n");
	i = 0;
	while (i < info->num_philos)
	{
		philo[i].id = i + 1;
		philo[i].meal_count = 0;
		philo[i].last_meal = 0;
		philo[i].curr_time = get_time() - info->start_time;
		philo[i].info = info;
		i++;
	}
	info->philo = philo;
}

void	init_mutexes(t_info *info)
{
	int i;
		
	i = 0;
	info->fork = (t_fork *)malloc(sizeof(t_fork) * info->num_philos);
	if (!info->fork)
		exit_program(info, MALLOC_ERROR);
	if (pthread_mutex_init(&info->print, NULL) != 0)
		exit_program(info, FAILURE_INFO);
	while (i < info->num_philos)
	{
		info->fork->id = 0;
		info->fork[i].mutex = (t_mutex *)malloc(sizeof(t_mutex));
		if (pthread_mutex_init(info->fork[i++].mutex, NULL) != 0)
		{
			while (i >= 0)
				pthread_mutex_destroy(info->fork[i--].mutex);
			exit_program(info, FAILURE_INFO);
		}
	}
}

t_info   *init_data(int argc, char **argv)
{
	t_info *info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		error_message(MALLOC_ERROR, "Malloc Error - info\n");
	info->num_philos = ft_atoll(argv[1]);
	info->time2die = ft_atoll(argv[2]);
	info->time2eat = ft_atoll(argv[3]);
	info->time2sleep = ft_atoll(argv[4]);
	if (argc == 6)
		info->max_meals = ft_atoll(argv[5]);
	else
		info->max_meals = -1;
	info->dead = 0;
	info->start_time = get_time();
	check_values(info);
	init_mutexes(info);
	init_philo(info);
	return (info);
}