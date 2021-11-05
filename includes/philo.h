/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:39:19 by josantos          #+#    #+#             */
/*   Updated: 2021/11/05 20:11:35 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

typedef enum s_state
{
	Sleeped,
	Ate,
	Died,
	Thought,
}	t_state;

typedef struct s_data
{
	int	*num_philos;
	int	*num_forks;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	eat_limit;
}	t_data;

void	argument_check(int argc, char **argv);
void	error_message(int type, char *message);
int		is_digit(char *str);
int		is_int(char	*str);
int		is_pos(char *str);

#endif
