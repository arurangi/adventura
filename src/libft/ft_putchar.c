/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:04:13 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/07 07:40:27 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Outputs the character {c} to the given file descriptor {fd}
*/

#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
