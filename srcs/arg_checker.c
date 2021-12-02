/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:06:27 by josantos          #+#    #+#             */
/*   Updated: 2021/12/02 19:28:10 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int argc, char **argv)
{
	int	i;

	if (argc < 5)
		return (error_message(ARGS_ERROR, "\nArguments missing!\n"));
	if (argc > 6)
		return (error_message(ARGS_ERROR, "\nToo many arguments!\n"));
	i = 1;
	while ((i + 1) <= argc)
	{
		if (is_digit(argv[i]) == 0)
			return (error_message(ARGS_ERROR,
					"\nGiven arguments are not digits!\n"));
		if (is_int(argv[i]) == 0)
			return (error_message(ARGS_ERROR,
					"\nGiven arguments must be integers!\n"));
		if (is_pos(argv[i]) == 0)
			return (error_message(ARGS_ERROR,
					"\nArguments have to be positive!\n"));
		i++;
	}
	return (SUCCESS);
}

int	check_values(t_info *info)
{
	if (info->num_philos <= 0)
	{
		printf("\n"B_RED "Number of Philosophers must be more than 0!" RESET"\n");
		return (FAILURE);
	}
	if (info->time2die <= 0 || info->time2eat <= 0 || info->time2sleep <= 0)
	{
		printf("\n"B_RED "Mandatory timers have to be more than 0!" RESET"\n");
		return (FAILURE);
	}
	return (SUCCESS);
}
