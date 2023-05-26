/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:29:26 by Arsene            #+#    #+#             */
/*   Updated: 2023/05/26 18:09:56 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Render/display every assets on the window
 * based on their location on the map
 */

#include "../so_long.h"

void	add_node_back(t_list **list, int x, int y)
{
	t_list	*new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->x = x;
	new->y = y;
	new->delay = 0; // random ???
	new->state = 0; // random ???
	new->next = NULL;

	if (!*list) {
		*list = new;
		return ;	
	}
	find_last_node(*list)->next = new;
}

t_list	*find_last_node(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next) {
		lst = lst->next;
	}
	return (lst);
}

void	draw_black_screen(t_game *game)
{
	int row, col;

	row = 0;
	while (row < game->map_height)
	{
		col = 0;
		while (col < game->map_width)
		{
			render_sprite_nohud(game, _wall_inside, col, row);
			col++;
		}
		row++;
	}
}

void	draw_map(t_game *game)
{
	int row, col;

	row = 0;
	while (row < game->map_height)
	{
		col = 0;
		while (col < game->map_width)
		{
			switch (game->map[row][col])
			{
				case '1':
					identify_walls(game, col, row);
					break ;
				case 'E':
					render_sprite(game, _exit_closed, col, row);
					break ;
				case 'C':
					render_sprite(game, _coins, col, row);
					break ;
				case 'T':
					render_sprite(game, _treasure_chest, col, row);
					break ;
				case 'N': {
					add_node_back(&game->enemies, col, row);
					render_sprite(game, _enemy1, col, row);
				}
					break ;
				default :
					render_sprite(game, _emptyspace, col, row);
					break ;
			}
			col++;
		}
		row++;
	}
}

void	render_and_update(t_game *game)
{
	mlx_loop_hook(game->mlx, &render, game);
}

int	render(t_game *game)
{
	int	row;
	int	col;

	if (game->player_moved)
	{
		render_hud_values(game);;
		render_sprite(game, game->plr_angle, game->x_shift, game->y_shift);
		update_life_points(game);
		game->player_moved = FALSE;
	}
	// animated objects {enemies, coins}
	print_list(game->enemies);

	t_list *enemy_list = game->enemies;
	while (enemy_list) {
		animate(game, enemy_list->x, enemy_list->y);
		enemy_list = enemy_list->next;
	}
	// traverse the list of enemies
		// update their state
		// move them
	
	row = 0;
	while (row < game->map_height)
	{
		col = 0;
		while (col < game->map_width)
		{
			// if (game->map[row][col] == 'N')
			// 	animate(game, col, row);
			if (game->map[row][col] == 'E' && game->c_credit == 0)
				render_sprite(game, _exit_opened, col, row);
			col++;
		}
		row++;
	}
	return (0);
}

void	identify_sprites(t_game *game, int row, int col)
{
	switch (game->map[row][col])
	{
		case '0': {
			//render_sprite(game, _emptyspace, col, row);
			break ;
		}
		case '1': {
			//identify_walls(game, col, row);
			break ;
		}
		case 'P': {
			// if (game->player_moved) {
			// 	//render_sprite(game, _emptyspace, game->x_last, game->y_last);
			// 	render_sprite(game, game->plr_angle, game->x_shift, game->y_shift);
			// }
			break ;
		}
		case 'C': {
			//render_sprite(game, _coins, col, row);
			break ;
		}
		case 'T': {
			//render_sprite(game, _treasure_chest, col, row);
			break ;
		}
		case 'E': {
			//identify_exit(game, col, row);
			break ;
		}
		case 'N': {
			animate(game, col, row);
			break ;
		}
	}
}

void	update_life_points(t_game *game)
{
	if (game->map[game->y_shift][game->x_shift] == 'N')
	{
		if ((game->delay % 21 == 20) && game->life_points > 0)
			game->life_points -= 1;
		usleep(1000);
	}
}
