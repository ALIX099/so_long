/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 02:00:54 by abouknan          #+#    #+#             */
/*   Updated: 2025/04/04 06:48:10 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_mlx(t_game *game, int w, int h)
{
	game->mlx_init = mlx_init();
	if (!game->mlx_init)
		return (error_handling("Mlx Can't be initialized!", game));
	game->mlx_win = mlx_new_window(game->mlx_init, game->map_x * 64, game->map_y
			* 64, "so_long");
	if (!game->mlx_win)
		return (error_handling("Mlx Window Can't Open!", game));
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
		return (free(game->mlx_win), error_handling("Mlx Xpm File To Image",
				game));
}

void	put_in_map(t_game *game, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx_init, game->mlx_win, game->wall, x,
			y);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx_init, game->mlx_win,
			game->exit_closed, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx_init, game->mlx_win, game->coin, x,
			y);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx_init, game->mlx_win, game->player, x,
			y);
	else if (c == '0')
		mlx_put_image_to_window(game->mlx_init, game->mlx_win, game->back, x,
			y);
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
			put_in_map(game, game->map[y][x], x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	move_player(t_game *game, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + x;
	new_y = game->player_y + y;
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'C' || game->map[new_y][new_x] == '0')
	{
		if (game->map[new_y][new_x] == 'C')
			game->collectible_count--;
		if (game->collectible_count == 0)
			mlx_put_image_to_window(game->mlx_init, game->mlx_win,
				game->exit_opened, game->e_x * 64, game->e_y * 64);
		game->map[game->player_y][game->player_x] = '0';
		put_in_map(game, '0', game->player_x * 64, game->player_y * 64);
		game->player_x = new_x;
		game->player_y = new_y;
		game->map[game->player_y][game->player_x] = 'P';
		put_in_map(game, 'P', new_x * 64, new_y * 64);
	}
	if (game->map[new_y][new_x] == 'E')
	{
		if (!game->collectible_count)
		{
			close_window_and_free(game);
			ft_printf(GREEN "You Won The Game!\n");
			exit(0);
		}
		else
			ft_printf(RED "Collect The Coins Before Exitting!\n");
	}
}
