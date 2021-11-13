/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:06:27 by josantos          #+#    #+#             */
/*   Updated: 2021/11/13 18:06:02 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	argument_check(int argc, char **argv)
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
			error_message(ARGS_ERROR, "Given arguments are not integers!\n");
		if (is_pos(argv[i]) == 0)
			error_message(ARGS_ERROR, "Arguments can't be negative!\n");
		i++;
	}
}

int	check_values(t_control *data)
{
	if (data->n_philos <= 0)
	{
		printf("\nNumber of Philosophers has to be more than 0!\n");
		return (1);
	}
	if (data->time2die <= 0 || data->time2eat <= 0 || data->time2sleep <= 0)
	{
		printf("\nMandatory timers have to be more than 0!\n");
		return (1);
	}
	return (0);
}
