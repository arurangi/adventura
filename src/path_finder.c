/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:08:25 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/25 13:08:38 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * path_finder()
 *
 * finds a path to the exit, if any
 * based on a map, a starting position and the position of a 
 * depending on walls
 * 
*/

#include "../so_long.h"

int	path_finder(t_game *game)
{
	int			q_size;
	int			head;
	int			tail;
	t_node		current;

	// Create new queue
	q_size = (game->map_height * game->map_width) + 1;
	t_node	queue[q_size];
	queue[0] = game->starting_pos;
	ft_printf("'P' at (%d, %d)\n", queue[0].row, queue[0].col);

	// Add all neighbours
	head = 0;
	tail = 0;
	add_neighbours(game, queue, head, &tail);
	head += 1;

	for (int i = head; i <= tail; i++)
		ft_printf("%c at (%d,%d)\n", game->map[queue[i].row][queue[i].col], queue[i].row, queue[i].col);
	// Add all of this person's friends to the queue
	// While the queue isn't empty
	while (head <= tail && tail < q_size)
	{
		// Grab first person off the queue
		current = queue[head];
		// Check whether node is an exit
		if (found_exit(game, current))
		{
			// You're done!
			ft_printf("\033[32mFound exit\033[0m at (%d, %d)\n", current.row, current.col);
			return (1);
		}
		else
		{
			// Add all of this person's friends to the queue
			//ft_printf("Adding \033[30m(%d, %d)\033[0m's neighbours\n", current.row, current.col);
			add_neighbours(game, queue, head, &tail);
		}
		head += 1;
	}
	// If you reached here, no one was a mango seller
	ft_printf("\n\033[31mNo EXIT found\033[0m");

	return (0);
}
