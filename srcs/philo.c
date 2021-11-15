/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:43:08 by josantos          #+#    #+#             */
/*   Updated: 2021/11/15 18:08:26 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo		*philo;
	t_control	*data;

	argument_check(argc, argv);
	data = init_data(argc, argv);
	philo = init_philo(data);
	exit_program(data, philo, FINISHED);
}
