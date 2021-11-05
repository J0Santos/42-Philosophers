/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:16:43 by josantos          #+#    #+#             */
/*   Updated: 2021/11/05 20:11:46 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	ft_strlen(const char *str)
{
	size_t	a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}

static long long	ft_atoll(char *str)
{
	long long			a;
	long long			b;
	long long			c;

	a = 0;
	b = 1;
	c = 0;
	while (str[a] == ' ' || (str[a] >= 9 && str[a] <= 13))
		a++;
	if ((str[a] == '-') || (str[a] == '+'))
	{
		if (str[a] == '-')
			b *= -1;
		a++;
	}
	while (str[a] >= 48 && str[a] <= 57)
	{
		c = (c * 10) + (b * (str[a] - '0'));
		a++;
	}
	return (c);
}

int	is_digit(char *str)
{
	int	i;
	int	a;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && ft_strlen(str) >= 2)
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			a = 1;
		else
			a = 0;
		if (a == 0)
			return (a);
		i++;
	}
	return (a);
}

int	is_int(char *str)
{
	long long	i;

	i = ft_atoll(str);
	if (i > 2147483647 || i < -2147483648)
		return (0);
	return (1);
}

int	is_pos(char *str)
{
	long long	i;

	i = ft_atoll(str);
	if (i < 0)
		return (0);
	return (1);
}
