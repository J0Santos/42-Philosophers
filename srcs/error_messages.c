/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:53:57 by josantos          #+#    #+#             */
/*   Updated: 2021/11/15 18:07:41 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_program(t_control *data, t_philo *philo, int type)
{
	destroy_mutexes(data);
	free(data);
	free(philo);
	if (type == THREAD_ERROR)
		error_message(THREAD_ERROR, "Thread Error\n");
	else
		exit(EXIT_SUCCESS);
}

void	error_message(int type, char *message)
{
	if (type == ARGS_ERROR)
	{
		printf("%s\n", message);
		printf("Allowed arguments must be:\n");
		printf("\t- Number of philosophers;\n");
		printf("\t- Time to die (milliseconds);\n");
		printf("\t- Time to eat (milliseconds);\n");
		printf("\t- Time to sleep (milliseconds);\n");
		printf("\t- (optional) Number of times each philosopher must eat;\n");
	}
	else
		printf("%s\n", message);
	exit(EXIT_FAILURE);
}
