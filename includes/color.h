/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:12:33 by josantos          #+#    #+#             */
/*   Updated: 2021/11/26 17:16:57 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

/* Color Rest */

# define RESET		"\033[0m"

/* Colors */

# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

/* Bold Font */

# define B_RED		"\033[31;1m"
# define B_GREEN	"\033[32;1m"
# define B_YELLOW	"\033[33;1m"
# define B_BLUE		"\033[34;1m"
# define B_MAGENTA	"\033[35;1m"
# define B_CYAN		"\033[36;1m"
# define B_WHITE	"\033[37;1m"

typedef char	*t_color;

#endif