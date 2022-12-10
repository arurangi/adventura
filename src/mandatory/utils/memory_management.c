/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:58:19 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/10 16:45:30 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long_bonus.h"

int	free_arr_nodes(int return_code, t_node *arr)
{
	free(arr);
	return (return_code);
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
