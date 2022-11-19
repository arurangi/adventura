/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:50:24 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/19 11:48:49 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Prints unsigned int to standard output
*/

#include "../libft.h"

int	ft_putnbr_u(unsigned int nbr, int *counter)
{
	char			ch;

	if (nbr > 9)
	{
		ft_putnbr_u((nbr / 10), counter);
		ft_putnbr_u((nbr % 10), counter);
	}
	else if (nbr >= 0 && nbr < 10)
	{
		(*counter)++;
		ch = nbr + '0';
		ft_putchar(ch);
	}
	return (*counter);
}
