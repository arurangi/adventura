/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:50:24 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/07 07:40:45 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Prints unsigned int to standard output
*/

#include "libft.h"

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
