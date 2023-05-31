/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:33:19 by lupin             #+#    #+#             */
/*   Updated: 2023/05/27 20:32:58 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "constants.h"

/* STRUCTURES */
typedef struct s_node{
	int row;
	int col;
}	t_node;


typedef struct s_list {
	int				x;
	int				y;
	int				frame;
	int				asset_offset;
	int				nbr_frames;
	int				direction;
	int				delay;
	u_int8_t		type;
	struct s_list	*next;
}	t_list;


typedef struct s_asset
{
	char	*path;
	void	*img;
	int		width;
	int		height;
}	t_asset;

typedef struct s_game {
	void		*mlx;
	void		*window;
	
	char		**map;
	char		*map_filepath;
	int			map_height;
	int			map_width;
	int			c_credit;
	int			e_credit;
	int			p_credit;
	t_node		starting_pos;
	
	t_asset		sprites[SPRITES_NBR];

	int			x_last;
	int			y_last;

	t_list		*enemies;
	
	int			x_shift;
	int			y_shift;
	int			plr_angle;
	int			polarity;
	
	int			animation_state;
	int			delay;
	
	int			steps_count;
	int			life_points;

	int			player_moved;
	
}	t_game;


#endif