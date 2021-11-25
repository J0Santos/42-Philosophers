/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:36:23 by josantos          #+#    #+#             */
/*   Updated: 2021/11/25 15:20:07 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_info *info;

	check_args(argc, argv);
	info = init_data(argc, argv);
	thread_create(info);
	exit_program(info, SUCCESS);
	return (0);
}