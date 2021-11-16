/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:02:34 by josantos          #+#    #+#             */
/*   Updated: 2021/11/16 12:32:47 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void destroy_mutexes(t_control *data)
{
    int i;
    
    i = 0;
    while (i < data->n_philos)
    {
        pthread_mutex_destroy(&(data->fork[i]));
        i++;
    }
    pthread_mutex_destroy(data->print);
 //   pthread_mutex_destroy(&(data->dead));
}

void    init_mutex(t_control *data)
{
    int i;

    i = data->n_philos;
    data->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * i);
    if (!data->fork)
        error_message(3, "Malloc error\n");
    i = 0;
    while (i < data->n_philos)
    {
        if (pthread_mutex_init(&(data->fork[i]), NULL) != 0)
        {
            while (i-- >= 0)
                pthread_mutex_destroy(&(data->fork[i]));
            error_message(2, "Mutex error");
        }
        i++;
    }
    if (pthread_mutex_init(data->print, NULL))
        pthread_mutex_destroy(data->print);
}