/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:04:13 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/19 11:48:23 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Outputs the character {c} to the given file descriptor {fd}
*/

#include "../libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
