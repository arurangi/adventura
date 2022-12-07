/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:33:02 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/07 07:40:37 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Prints integer in hexadecimal format
*/

#include "libft.h"

int	ft_puthex(unsigned long nbr, char format, int *counter)
{
	char	ch;
	char	*base;

	base = "0123456789abcdef";
	if (nbr > 16 - 1)
	{
		ft_puthex(nbr / 16, format, counter);
		ft_puthex(nbr % 16, format, counter);
	}
	else
	{
		(*counter)++;
		ch = base[nbr];
		if (format == 'X' && ft_isalpha(ch))
			ch -= 32;
		ft_putchar(ch);
	}
	return (*counter);
}
