/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:38:48 by arurangi          #+#    #+#             */
/*   Updated: 2023/05/31 10:30:48 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_msg(int return_code, char *message, ...)
{
	va_list	args;
	int		index;

	ft_putstr("\033[31mError\033[0m\n✖ ");
	va_start(args, message);
	index = 0;
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
	return (return_code);
}

void	error_usage(char *msg1, char *msg2)
{
	ft_putstr("\033[31mError\033[0m (Usage)\n");
	
	if (msg1)
		printf("|_ %s\n", msg1);
	if (msg2)
		printf("|_ %s\n", msg2);
}

int	success_msg(int return_code, char *message, ...)
{
	va_list	args;
	int		index;

	ft_putstr("\033[32m✓\033[0m ");
	va_start(args, message);
	index = 0;
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
	return (return_code);
}
