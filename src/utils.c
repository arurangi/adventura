/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:15:12 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/25 15:16:38 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * List of short but usefull functions
*/

#include "../libft.h"

int	invalid_extension(char *filepath)
{
	int		len;

	len = ft_strlen(filepath);
	if ((len > 4) 
		&& (filepath[len - 1] == 'r'
		&& filepath[len - 2] == 'e'
		&& filepath[len - 3] == 'b'
		&& filepath[len - 4] == '.'))
		return (0);
	return (1);
}