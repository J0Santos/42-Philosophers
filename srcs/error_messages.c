/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:53:57 by josantos          #+#    #+#             */
/*   Updated: 2021/11/23 12:03:19 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
