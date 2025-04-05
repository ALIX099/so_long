/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helper_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:08:56 by abouknan          #+#    #+#             */
/*   Updated: 2025/04/05 13:23:00 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	close_window_and_free_two(t_game *game);

void	error_handling(char *message, t_game *game)
{
	if (game->mlx_init)
		free(game->mlx_init);
	ft_printf(RED "Error\n%s\n", message);
	return (split_free(game->map, count_splited(game->map)), exit(1));
}

void	close_window_and_free(t_game *game)
{
	mlx_destroy_window(game->mlx_init, game->mlx_win);
	if (game->player_down)
		mlx_destroy_image(game->mlx_init, game->player_down);
	if (game->player_right)
		mlx_destroy_image(game->mlx_init, game->player_right);
	if (game->player_left)
		mlx_destroy_image(game->mlx_init, game->player_left);
	if (game->player_up)
		mlx_destroy_image(game->mlx_init, game->player_up);
	if (game->coin)
		mlx_destroy_image(game->mlx_init, game->coin);
	if (game->back)
		mlx_destroy_image(game->mlx_init, game->back);
	if (game->img_killer[0])
		mlx_destroy_image(game->mlx_init, game->img_killer[0]);
	if (game->img_killer[1])
		mlx_destroy_image(game->mlx_init, game->img_killer[1]);
	if (game->img_killer[2])
		mlx_destroy_image(game->mlx_init, game->img_killer[2]);
	if (game->wall)
		mlx_destroy_image(game->mlx_init, game->wall);
	if (game->exit_closed)
		mlx_destroy_image(game->mlx_init, game->exit_closed);
	close_window_and_free_two(game);
}

static void	close_window_and_free_two(t_game *game)
{
	if (game->exit_opened)
		mlx_destroy_image(game->mlx_init, game->exit_opened);
	if (game->mlx_init)
	{
		mlx_destroy_display(game->mlx_init);
		free(game->mlx_init);
	}
	if (game->map)
		split_free(game->map, count_splited(game->map));
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
		mlx_put_image_to_window(game->mlx_init, game->mlx_win,
			game->player_down, x, y);
	else if (c == '0')
		mlx_put_image_to_window(game->mlx_init, game->mlx_win, game->back, x,
			y);
	else if (c == 'T')
		mlx_put_image_to_window(game->mlx_init, game->mlx_win, game->img_killer[game->killer_frame],
			x, y);
}

int	key_code(int key, t_game *game)
{
	if (key == KEY_ESC)
		return (close_window_and_free(game),
			ft_printf(CYAN "You Exit the Game!\n"), exit(0), 0);
	else if (key == KEY_W || key == KEY_UP)
		move_player(game, 0, -1, "UP");
	else if (key == KEY_S || key == KEY_DOWN)
		move_player(game, 0, 1, "DOWN");
	else if (key == KEY_A || key == KEY_LEFT)
		move_player(game, -1, 0, "LEFT");
	else if (key == KEY_D || key == KEY_RIGHT)
		move_player(game, 1, 0, "RIGHT");
	return (0);
}
