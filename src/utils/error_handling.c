/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:38:48 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/06 10:21:34 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	error_found(char *str)
{
	ft_printf("%s\n", str);
	return (0);
}

void	free_matrix(char **matrix)
{
	int	i;
	
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	map_error(t_game *game, char *message, ...)
{
	va_list	args;
	int index;

	if (game->map)
		free_matrix(game->map);
	ft_printf("\033[31m✖ Map error: \033[0m ");
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
	return (0);
}

int	game_error(char *message, ...)
{
	va_list	args;
	int index;

	ft_printf("\033[31m✖ Game error: \033[0m ");
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
	return (1);
}

int success_msg(int code, char *message, ...)
{
	va_list	args;
	int index;

	ft_printf("\033[32m✓\033[0m ");
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
	return (code);
}

void	free_assets(t_game *game)
{
	int i = 0;
	
	while (i < 16)
	{
		mlx_destroy_image(game->mlx, game->sprites[i].img);
		i++;
	}
}
