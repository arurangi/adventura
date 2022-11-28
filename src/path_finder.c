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

	head = 0;
	tail = 0;
	// Create new queue
	q_size = (game->map_height * game->map_width) + 1;
	t_node	queue[q_size];
	queue[head] = game->starting_pos;
	ft_printf("+--------------------+\n| Starting at (%d, %d) |\n+--------------------+\n\n", queue[head].row, queue[head].col);

	// Add all neighbours
	add_neighbours(game, queue, head, &tail);

	// While the queue isn't empty
	while (head <= tail && tail < q_size)
	{
		// Grab first person off the queue
		current = queue[head];
		ft_printf("\n\033[34mchecking\033[0m (%d, %d)\n", current.row, current.col);
		// Check whether node is an exit
		if (found_exit(game, current))
		{
			// You're done!
			ft_printf("\n\033[32mFound exit\033[0m at (%d, %d)\n", current.row, current.col);
			return (1);
		}
		else
		{
			// Add all of this person's friends to the queue
			add_neighbours(game, queue, head, &tail);
		}
		head += 1;
		ft_printf("-- In queue: ");
		for (int i = head; i < tail; i++)
			ft_printf("(%d, %d) ", queue[i].row, queue[i].col);
		ft_printf("\n");
	}
	// If you reached here, no one was a mango seller
	ft_printf("\n\033[31mNo EXIT found\033[0m");

	return (0);
}
