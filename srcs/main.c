/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:36:23 by josantos          #+#    #+#             */
/*   Updated: 2021/11/26 22:01:39 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_info *info;

	if (check_args(argc, argv))
		return (FAILURE);
	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (error_message(MALLOC_ERROR, "Malloc Error - info\n"));
	if (init_data(info, argc, argv))
		return(FAILURE);
	if (thread_create(info))
		return (FAILURE);
	finish_program(info);
	return (SUCCESS);
}