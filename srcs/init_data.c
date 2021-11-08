/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:16:06 by josantos          #+#    #+#             */
/*   Updated: 2021/11/08 17:46:28 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(int argc, char **argv)
{
	t_philo philo;
	t_data	data;
	int i;
	int j;

	i = 0;
	j = ft_atoll(argv[1]);

	philo.death = ft_atoll(argv[2]);
	philo.eat = ft_atoll(argv[3]);
	philo.sleep = ft_atoll(argv[4]);
	if (argc == 6)
		data.eat_limit = ft_atoll(argv[5]);
}
