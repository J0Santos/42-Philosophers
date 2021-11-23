/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:58:03 by josantos          #+#    #+#             */
/*   Updated: 2021/11/23 18:33:41 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutexes(t_info *info)
{
	int i;
		
	i = 0;
	info->fork = (t_mutex *)malloc(sizeof(t_mutex) * info->num_philos);
	if (!info->fork)
		error_message(MALLOC_ERROR, "Malloc Error - fork");
	while (i < info->num_philos)
	{
		if (pthread_mutex_init(&info->fork[i++], NULL) != 0)
		{
			while (i >= 0)
				pthread_mutex_destroy(&info->fork[i--]);
			exit_program(info);
		}
	}
	if (pthread_mutex_init(&info->print, NULL) != 0)
		exit_program(info);
}

t_philo	*init_philo(t_info *info)
{
	t_philo	*philo;
	static int	i = 0;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		error_message(MALLOC_ERROR, "Malloc error - philo");
	philo->id = i++;
	philo->meal_count = 0;
	philo->last_meal = 0;
	philo->info = info;
	//philo->thread = init_thread(info, philo);
	return (philo);
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
	init_mutexes(info);
	while (i < info->num_philos)
		info->philo[i++] = *init_philo(info);
	return (info);
}