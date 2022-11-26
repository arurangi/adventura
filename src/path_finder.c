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
	int		size;
	int		head;
	int		tail;

	// Create new queue
	size = game->map_height * game->map_width;
	t_node	queue[size];
	head = 0;
	tail = 0;
	// Add initial position
	queue[head] = game->starting_pos;
	ft_printf("row: %d, col: %d\n", queue[0].row, queue[0].col);
	/*
	// Add all of neighbour to search queue
	enqueue(&queue, &head, &tail, size);
	// While the queue isn't empty
	while (q_not_empty(queue))
	{
		// Grab first person off the queue
		current = pop_head_queue();
		// Check whether the person is a mango seller
		if (not_visited())
		{
			if (found_exit(queue.ch))
			{
				// You're done!
				return (1);
			}
			else
			{
				// Add all of this person's friends to the queue
				// Mark that person as searched/visited
			}
		}
	}
	// If you reached here, no one was a mango seller
	*/
	return (1);
}

t_node	add_node(int row, int col)
{
	t_node	node;

	node.row = row;
	node.col = col;
	return (node);
}

/*
void	insert_neighbours(t_node *queue, int *head, int *tail, int size)
{
	int row;
	int	col;

	row = queue[*head].row;
	col = queue[*tail].col;
	if (tail == size - 1 || head > tail)
		printf("Queue Overflow n");
	else
	{
		queue[*head + 1] = ;
		*head++;
		*tail++;
	}
}
*/
// dequeue();
// q_is_empty();

int	found_exit(char ch)
{
	if (ch == 'E')
		return (1);
	return (0);
}
