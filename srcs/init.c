/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:02:47 by josantos          #+#    #+#             */
/*   Updated: 2021/11/12 16:10:23 by josantos         ###   ########.fr       */
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
	init_mutex(data);
	return (data);
}

t_philo	*init_philo(int argc, char **argv)
{
	t_control	*philo;
	

	philo = 
}