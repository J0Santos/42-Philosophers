/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:53:57 by josantos          #+#    #+#             */
/*   Updated: 2021/11/13 17:59:36 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_program(t_control *data, t_philo *philo, int type)
{
	if (type != MUTEX_ERROR)
		destroy_mutexes(data);
	printf("%s\n", str);
	free(data);
	free(philo);
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
	else if(type == MUTEX_ERROR)
	{
		
	}
	else
		printf("%s\n", message);
	exit(EXIT_FAILURE);
}
