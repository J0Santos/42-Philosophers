/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:43:08 by josantos          #+#    #+#             */
/*   Updated: 2021/11/16 12:06:16 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo		*philo;
	t_control	*data;

	printf("1\n");
	argument_check(argc, argv);
	printf("2\n");
	data = init_data(argc, argv);
	printf("3\n");
 	philo = init_philo(data);
	 printf("4\n");
	exit_program(data, philo, FINISHED);
}
