/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:53:57 by josantos          #+#    #+#             */
/*   Updated: 2021/12/02 19:29:56 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_message(int type, char *message)
{
	if (type == ARGS_ERROR)
	{
		printf(""B_RED "%s" RESET"\n", message);
		printf(""GREEN "Arguments must be:\n");
		printf("\t- Number of philosophers;\n");
		printf("\t- Time to die (milliseconds);\n");
		printf("\t- Time to eat (milliseconds);\n");
		printf("\t- Time to sleep (milliseconds);\n");
		printf("\t- (optional) Times each philosopher must eat;"RESET"\n");
	}
	else
		printf(""RED "%s" RESET"\n", message);
	return (FAILURE);
}
