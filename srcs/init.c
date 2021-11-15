/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:02:47 by josantos          #+#    #+#             */
/*   Updated: 2021/11/15 18:22:03 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_control *init_data(int argc, char **argv)
{
	t_control *data;

	data = malloc(sizeof(t_control));
	if (!data)
		error_message(2, "Malloc error\n");
	data->n_philos = ft_atoll(argv[1]);
	data->time2die = ft_atoll(argv[2]);
	data->time2eat = ft_atoll(argv[3]);
	data->time2sleep = ft_atoll(argv[4]);
	if (argc == 6)
		data->eat_limit = ft_atoll(argv[5]);
	else
		data->eat_limit = -1;
	if (check_values(data) != 0)
		error_message(1, "\nInsert values again\n");
	init_mutex(data);
	malloc_thread(data);
	return (data);
}

t_philo	*init_philo(t_control *data)
{
	t_philo	*philo;
	static int	i;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		error_message(2, "Malloc error\n");
	philo->data = data;
	i = 0;
	philo->id = ++i;
	philo->state = Thinking;
	philo->last_meal = 0;
	philo->times_ate = 0;
	philo->alive = 1;
	init_thread(data, philo);
	return (philo);
}