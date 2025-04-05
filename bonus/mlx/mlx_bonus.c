/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:08:58 by abouknan          #+#    #+#             */
/*   Updated: 2025/04/05 14:03:00 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void		init_two(t_game *game, int w, int h);

void	init_mlx(t_game *game, int w, int h)
{
	game->mlx_init = mlx_init();
	if (!game->mlx_init)
		return (error_handling("Mlx Can't be initialized!", game));
	game->mlx_win = mlx_new_window(game->mlx_init, game->map_x * w, game->map_y
			* h, "so_long");
	if (!game->mlx_win)
		return (error_handling("Mlx Can't be initialized!", game));
	game->coin = mlx_xpm_file_to_image(game->mlx_init, "textures/coin.xpm", &w,
			&h);
	game->back = mlx_xpm_file_to_image(game->mlx_init, "textures/back.xpm", &w,
			&h);
	game->player_down = mlx_xpm_file_to_image(game->mlx_init,
			"textures/player.xpm", &w, &h);
	game->player_left = mlx_xpm_file_to_image(game->mlx_init,
			"textures/player_left.xpm", &w, &h);
	game->player_up = mlx_xpm_file_to_image(game->mlx_init,
			"textures/player_up.xpm", &w, &h);
	game->player_right = mlx_xpm_file_to_image(game->mlx_init,
			"textures/player_right.xpm", &w, &h);
	game->wall = mlx_xpm_file_to_image(game->mlx_init, "textures/wall.xpm", &w,
			&h);
	game->exit_closed = mlx_xpm_file_to_image(game->mlx_init,
			"textures/closed_exit.xpm", &w, &h);
	init_two(game, w, h);
}

void	init_two(t_game *game, int w, int h)
{
	game->exit_opened = mlx_xpm_file_to_image(game->mlx_init,
			"textures/opened_exit.xpm", &w, &h);
	game->img_killer[0] = mlx_xpm_file_to_image(game->mlx_init,
			"textures/enemy_one.xpm", &w, &h);
	game->img_killer[1] = mlx_xpm_file_to_image(game->mlx_init,
			"textures/enemy_two.xpm", &w, &h);
	game->img_killer[2] = mlx_xpm_file_to_image(game->mlx_init,
			"textures/enemy_three.xpm", &w, &h);
	game->img_killer[3] = mlx_xpm_file_to_image(game->mlx_init,
			"textures/enemy_four.xpm", &w, &h);
	game->img_killer[4] = mlx_xpm_file_to_image(game->mlx_init,
			"textures/enemy_five.xpm", &w, &h);
	if (!game->coin || !game->back || !game->img_killer[0] || !game->img_killer[1]
		|| !game->img_killer[2] || !game->exit_closed || !game->exit_opened
		|| !game->player_down || !game->player_left || !game->player_up
		|| !game->player_right || !game->wall || !game->img_killer[3]
		|| !game->img_killer[4])
	{
		close_window_and_free(game);
		ft_printf(RED "Error\nMlx Xpm File To Image\n");
		exit(1);
	}
}

void	put_image_in_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			put_in_map(game, game->map[y][x], x * 40, y * 40);
			x++;
		}
		y++;
	}
	ft_print_movements(game);
}

static void	reach_exit(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->collectible_count == 0)
		{
			ft_printf(YELLOW "%d" CYAN " : " YELLOW "Move", ++game->move_count);
			close_window_and_free(game);
			print_win_message();
			exit(0);
		}
		else
			ft_printf(RED "Collect The Coins Before Exitting!\n");
	}
}

void	move_player(t_game *game, int x, int y, char *move_name)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + x;
	new_y = game->player_y + y;
	game->move_count = 0;
	if (game->map[new_y][new_x] == '1')
		return ;
	reach_empty_or_coin(game, new_x, new_y, move_name);
	reach_exit(game, new_x, new_y);
	reach_enemy(game, new_x, new_y);
}
