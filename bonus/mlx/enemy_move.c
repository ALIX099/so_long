/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 09:57:25 by abouknan          #+#    #+#             */
/*   Updated: 2025/04/08 15:15:13 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	custom_rand(unsigned int *seed)
{
	*seed = (1103515245 * *seed + 12345) % 2147483648;
	return (*seed % 3);
}

static void	put_enemy_image(t_game *game, int x, int y, int new_x)
{
	int	new_y;

	game->map[y][x] = '0';
	mlx_put_image_to_window(game->mlx_init, game->mlx_win, game->back, x * 40, y
		* 40);
	new_x = x + (custom_rand(&game->enemy_seed) - 1);
	new_y = y + (custom_rand(&game->enemy_seed) - 1);
	if (new_x >= 0 && new_x < game->map_x && game->map[y][new_x] == '0')
	{
		game->map[y][new_x] = 'T';
		mlx_put_image_to_window(game->mlx_init, game->mlx_win,
			game->img_killer[game->killer_frame], new_x * 40, y * 40);
	}
	else if (new_y >= 0 && new_y < game->map_y && game->map[new_y][x] == '0')
	{
		game->map[new_y][x] = 'T';
		mlx_put_image_to_window(game->mlx_init, game->mlx_win,
			game->img_killer[game->killer_frame], x * 40, new_y * 40);
	}
	else
	{
		game->map[y][x] = 'T';
		mlx_put_image_to_window(game->mlx_init, game->mlx_win,
			game->img_killer[game->killer_frame], x * 40, y * 40);
	}
}

void	move_enemies(t_game *game)
{
	int	y;
	int	x;
	int	new_x;

	y = 0;
	new_x = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'T')
				put_enemy_image(game, x, y, new_x);
			x++;
		}
		y++;
	}
}
