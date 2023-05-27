/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:31:42 by lupin             #+#    #+#             */
/*   Updated: 2023/05/27 12:43:06 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "structures.h"

/* START/END */
int			game_init(t_game *game, char **av);
void		start_game(t_game *game);
int			end_game(t_game *game);

/* INITIALIZATION */
void		map_init(t_game *game, char **av);
void		player_init(t_game *game);

/* MAP RELATED */
int			map_checker(t_game *game);
int			valid_character(char ch);
int			invalid_extension(char *filepath);
int			inner_loop_checker(t_game *game, int row, int col);
int			outer_loop_checker(t_game *game);

int			path_finder(t_game *game);
void		q_init(t_node *queue, int q_size);
t_node		add_node(int row, int col);
void		add_neighbours(t_game *game, t_node *queue, int head, int *tail);
int			found_exit(t_game *game, t_node node);
int			in_queue(t_node current, t_node *queue, int head, int tail);
int			valid_position(t_game *game, int row, int col, t_node current);
int			tab_height(char **tab);

/* INPUT */
int			handle_input(int keysym, t_game *game);
void		move(t_game *game, int keysym, int x, int y);
int			is_walkable(t_game *game, char ch);
int			is_walkable_enemy(char ch);
int			is_arrow_keys(int keysym);

/* RENDERING */
int			load_assets(t_game *game);
int			save_assets(t_game *game);

int			render(t_game *game);
void		render_sprite(t_game *game, int asset, int col, int row);
void		render_hud(t_game *game);
void		render_hud_values(t_game *game);

void		animate(t_game *game, int x, int y);
void		add_delay(t_game *game, int frame);

void		identify_sprites(t_game *game, int row, int col);
void		identify_walls(t_game *game, int x, int y);
void		identify_exit(t_game *game, int x, int y);
void		top_walls(t_game *game, int x, int y);
void		bottom_walls(t_game *game, int x, int y);
void		inner_walls(t_game *game, int x, int y);

int			rgbify(uint8_t red, uint8_t green, uint8_t blue);

/* Memory management */
int			free_arr_nodes(int return_code, t_node *queue);
void		free_matrix(char **matrix);
void		free_hud(char **hud_data);

/* ERROR HANDLING */
int			error_msg(int return_code, char *message, ...);
int			success_msg(int return_code, char *message, ...);

void		update_life_points(t_game *game);
void		render_and_update(t_game *game);
void		process_input(t_game *game);

void		draw_map(t_game *game);
void		draw_black_screen(t_game *game);
void		render_sprite_nohud(t_game *game, int asset, int col, int row);

// Lists
t_list		*find_last_node(t_list *lst);
void		ft_lstadd_back(t_list **lst, int x, int y);
void		print_list(t_list *list);

#endif