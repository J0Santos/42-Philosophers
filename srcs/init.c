/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:58:03 by josantos          #+#    #+#             */
/*   Updated: 2021/11/24 17:42:15 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutexes(t_info *info)
{
	int i;
		
	i = 0;
	info->fork = (t_mutex *)malloc(sizeof(t_mutex) * info->num_philos);
	if (!info->fork)
		exit_program(info, MALLOC_ERROR);
	if (pthread_mutex_init(&info->print, NULL) != 0)
		exit_program(info, FAILURE_INFO);
	while (i < info->num_philos)
		if (pthread_mutex_init(&info->fork[i++], NULL) != 0)
		{
			while (i >= 0)
				pthread_mutex_destroy(&info->fork[i--]);
			exit_program(info, FAILURE_INFO);
		}
}

void	init_philo(t_info *info)
{
	int		i;

	info->philo = (t_philo *)malloc(sizeof(t_philo));
	if (!info->philo)
		error_message(MALLOC_ERROR, "Malloc error - philo");
	i = 0;
	while (i < info->num_philos)
	{
		info->philo[i].id = i + 1;
		info->philo[i].meal_count = 0;
		info->philo[i].last_meal = 0;
		info->philo[i].info = info;
	//philo->thread = init_thread(info, philo);
		i++;
	}
}

t_info   *init_data(int argc, char **argv)
{
	t_info *info;
	int	i;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		error_message(MALLOC_ERROR, "Malloc Error - info");
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
	i = 0;
	//init_mutexes(info);
	//init_philo(info);
	return (info);
}