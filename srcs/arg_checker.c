/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:06:27 by josantos          #+#    #+#             */
/*   Updated: 2021/11/05 20:13:05 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	argument_check(int argc, char **argv)
{
	int i;

	if (argc < 5)
		error_message(1, "Arguments missing");
	if (argc > 6)
		error_message(1, "Too many arguments");
	i = 1;
	while ((i + 1) <= argc)
	{
		if (is_digit(argv[i]) == 0)
			error_message(1, "Given arguments are not digits\n");
		if (is_int(argv[i]) == 0)
			error_message(1, "Given arguments are not integers\n");
		if (is_pos(argv[i]) == 0)
			error_message(1, "Arguments can not be negative\n");
		i++;
	}
}
