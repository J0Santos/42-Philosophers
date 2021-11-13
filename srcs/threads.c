/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:04:13 by josantos          #+#    #+#             */
/*   Updated: 2021/11/13 17:29:20 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    malloc_thread(t_control *data)
{
    data->thread = malloc(sizeof(pthread_t) * data->n_philos);
    if (!data->thread)
        error_message(2, "Malloc error");
}

void    init_thread(t_control *data, t_philo *philo)
{
    int i;
    
    i = philo->id - 1;
    if (pthread_create(&(data->thread[i]), NULL, &routine, philo) != 0)
        
}