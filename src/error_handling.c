/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:38:48 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/29 12:35:33 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	error_found(char *str)
{
	ft_printf("%s\n", str);
	return (0);
}

int	map_error(char *message, ...)
{
	va_list	args;
	int index;

	index = 0;
	va_start(args, message);
	write(1, "\033[31m✖ Map_error\033[0m ", 23);
	while (message[index])
	{
		
		if (message[index] == '%')
		{
			if (message[index + 1] == 's')
				ft_putstr(va_arg(args, char *));
			else if (message[index + 1] == 'd')
				ft_putnbr(va_arg(args, int));
			index++;
		}
		else
			ft_putchar(message[index]);
		index++;
	}
	write(1, "\n", 1);
	return (0);
}