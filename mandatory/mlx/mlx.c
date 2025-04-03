/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 02:00:54 by abouknan          #+#    #+#             */
/*   Updated: 2025/04/03 11:27:32 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_mlx(t_game *game, int w, int h)
{
	game->mlx_init = mlx_init();
	if (!game->mlx_init)
		return (error_handling("Mlx Can't be initialized!\n", game));
	game->mlx_win = mlx_new_window(game->mlx_init, game->map_x * 64, game->map_y
			* 64, "so_long");
	if (!game->mlx_win)
		return (error_handling("Mlx Can't be initialized!\n", game));
	game->coin = mlx_xpm_file_to_image(game->mlx_init, "textures/coin.xpm", &w,
			&h);
	game->player = mlx_xpm_file_to_image(game->mlx_init, "textures/player.xpm",
			&w, &h);
	game->exit_closed = mlx_xpm_file_to_image(game->mlx_init,
			"textures/closed_exit.xpm", &w, &h);
	game->exit_opened = mlx_xpm_file_to_image(game->mlx_init,
			"textures/opened_exit.xpm", &w, &h);
	game->wall = mlx_xpm_file_to_image(game->mlx_init, "textures/wall.xpm", &w,
			&h);
	game->back = mlx_xpm_file_to_image(game->mlx_init, "textures/back.xpm", &w,
			&h);
	if (!game->coin || !game->player || !game->exit_closed || !game->exit_opened
		|| !game->wall || !game->back)
		return (free(game->mlx_win),
			error_handling("Error : While mlx xpm file to image", game));
}

void	put_image_in_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map_y)
	{
		x = 0;
		while (x < game->map_x)
		{
			put_in_map(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}
