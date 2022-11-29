/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:32:11 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/29 12:30:36 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Prints integer {nbr} to standard output
*/

#include "../so_long.h"

int	ft_putnbr_mod(int nbr, int *counter)
{
	char	ch;

	if (nbr > 9)
	{
		ft_putnbr_mod((nbr / 10), counter);
		ft_putnbr_mod((nbr % 10), counter);
	}
	else if (nbr == INT_MIN)
	{
		return (ft_putstr("-2147483648") + *counter);
	}
	else if (nbr < 0)
	{
		(*counter)++;
		ft_putchar('-');
		nbr = -nbr;
		ft_putnbr_mod(nbr, counter);
	}
	else if (nbr >= 0 && nbr < 10)
	{
		(*counter)++;
		ch = nbr + '0';
		ft_putchar(ch);
	}
	return (*counter);
}
