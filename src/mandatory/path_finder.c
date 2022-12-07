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
 * finds path to exit using 'breath-first search algorithm'
 * an 'adjacency matrix' to represent the graph
 * and a queue as data structure
*/

#include "../../so_long.h"

int	path_finder(t_game *game)
{
	t_node		*queue;
	int			head;
	int			tail;
	t_node		current;

	queue = malloc(sizeof(t_node) * game->map_height * game->map_width + 1);
	if (!queue)
		return (error_msg(0, "couldn't allocate memory for the QUEUE"));
	q_init(queue, game->map_height * game->map_width);
	head = 0;
	tail = 0;
	queue[head] = game->starting_pos;
	add_neighbours(game, queue, head, &tail);
	while (queue[head].row != -1)
	{
		current = queue[head];
		if (found_exit(game, current))
			return (free_array(0, queue));
		add_neighbours(game, queue, head, &tail);
		head++;
	}
	free(queue);
	return (error_msg(0, "no EXIT found"));
}
