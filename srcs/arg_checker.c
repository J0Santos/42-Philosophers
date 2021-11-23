/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:06:27 by josantos          #+#    #+#             */
/*   Updated: 2021/11/23 12:12:12 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_args(int argc, char **argv)
{
	int i;

	if (argc < 5)
		error_message(ARGS_ERROR, "Arguments missing!");
	if (argc > 6)
		error_message(ARGS_ERROR, "Too many arguments!");
	i = 1;
	while ((i + 1) <= argc)
	{
		if (is_digit(argv[i]) == 0)
			error_message(ARGS_ERROR, "Given arguments are not digits!\n");
		if (is_int(argv[i]) == 0)
			error_message(ARGS_ERROR, "Given arguments must be integers!\n");
		if (is_pos(argv[i]) == 0)
			error_message(ARGS_ERROR, "Arguments have to be positive!\n");
		i++;
	}
}

int	check_values(t_info *info)
{
	if (info->num_philos <= 0)
	{
		printf("\nNumber of Philosophers must be more than 0!\n");
		return (1);
	}
	if (info->time2die <= 0 || info->time2eat <= 0 || info->time2sleep <= 0)
	{
		printf("\nMandatory timers have to be more than 0!\n");
		return (1);
	}
	return (0);
}
