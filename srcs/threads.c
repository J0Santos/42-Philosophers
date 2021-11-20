/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:04:13 by josantos          #+#    #+#             */
/*   Updated: 2021/11/19 12:46:11 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    malloc_thread(t_control *data)
{
    data->thread = (pthread_t *)malloc(sizeof(pthread_t) * data->n_philos);
    if (!data->thread)
        error_message(2, "Malloc error");
}

void    *routine(void *philo)
{
    t_philo *philosopher;
    
    philosopher = philo;
    printf("Philo %d says HI\n", philosopher->id);
    return (0);
}

void    init_thread(t_control *data, t_philo *philo)
{
    int i;

    i = 0;
    while (i < data->n_philos)
    {
        if (pthread_create(&data->thread[i], NULL, &routine, philo) != 0)
            exit_program(data, philo, THREAD_ERROR);
        i++;
    }
    i = 0;
    while (i < data->n_philos)
    {
        if (pthread_join(data->thread[i], NULL) != 0)
            exit_program(data, philo, THREAD_ERROR);
        i++;
    }
}