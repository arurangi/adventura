/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playground.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:38:42 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/14 14:30:33 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Trying things out
*/

/*

// count enemies in order to allocate memory for each

// Initialize number of enemy
game->n_credit = 0;
// Count number of enemy on the map
if (game->map[row][col] == 'N')
    game->n_credit++;
// Allocate memory for each enemy
t_asset *enemies;

enemies = malloc(sizeof(t_asset) * game->n_credit + 1);
if (enemies == NULL)
    return (error_msg(0, "can't allocate memory to enemies"));
// Save location of each enemy
int row = 0, col, enemy_id = 0;

if (game->n_credit == 0)
    return (0);
while (row < game->map_height)
{
    col = 0;
    while (col < game->map_width)
    {
        if (game->map[row][col] == 'N')
        {
            enemies[n_id].x = col;
            enemies[n_id].y = row;
            load_assets(enemy, n_id);
            enemy_id++;
        }
        col++;
    }
    row++;
}
// Load assets for each enemy
void    load_assets(t_assets *enemies, int n_id)
{
    // Save path for each frames
    enemies[n_id].frames[0].path = "./assets/sprites/enemy_0";
    enemies[n_id].frames[1].path = "./assets/sprites/enemy_1";
    enemies[n_id].frames[2].path = "./assets/sprites/enemy_2";
    enemies[n_id].frames[3].path = "./assets/sprites/enemy_3";

    // Save image ptr
    int i = 0;
    while (i < MAX_FRAMES)
    {
        enemies[n_id].frames[i].img = mlx_xpm_to_window(game->mlx,
            enemies[n_id].frame[i].path,
            &enemies[n_id].frames[i].width,
            &enemies[n_id].frames[i].height);
        if (enemies[n_id].frames[i].img == NULL)
            return (error_msg(0, "can't save data to enemy ID %d", n_id));
        i++;
    }
}

*/