/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:58:19 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/14 14:30:06 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

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

void	free_hud(char **hud_data)
{
	free(hud_data[0]);
	free(hud_data[1]);
}
