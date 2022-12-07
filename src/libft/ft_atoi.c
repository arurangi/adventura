/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:49:42 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/07 07:39:36 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Converts a string {str} into an integer
 * 
 * Returns : the integer
*/

#include "libft.h"

static int	handle_long_return(long sign);

int	ft_atoi(const char *str)
{
	int		index;
	long	sum;
	long	sign;

	index = 0;
	while ((((str[index] >= 9 && str[index] <= 13) || str[index] == 32)))
		index++;
	sign = 1;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign *= -1;
		index++;
	}
	sum = 0;
	while (str[index] >= 48 && str[index] <= 57)
	{
		if (sum >= LONG_MAX / 10 || (sum == LONG_MAX && str[index] - '0' > 7))
			handle_long_return(sign);
		sum = (sum * 10) + (str[index] - '0');
		index++;
	}
	return (sum * sign);
}

static int	handle_long_return(long sign)
{
	if (sign == 1)
		return (-1);
	else
		return (0);
}
