/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 07:17:52 by abouknan          #+#    #+#             */
/*   Updated: 2025/04/04 10:47:46 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_e_x_e_y(t_game *game)
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
			if (game->map[y][x] == 'E')
			{
				game->e_x = x;
				game->e_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	error_handling(char *message, t_game *game)
{
	free(game->mlx_init);
	ft_printf(RED "Error\n%s\n", message);
	return (split_free(game->map, count_splited(game->map)), exit(1));
}

void	close_window_and_free(t_game *game)
{
	if (game->mlx_win)
		mlx_destroy_window(game->mlx_init, game->mlx_win);
	if (game->coin)
		mlx_destroy_image(game->mlx_init, game->coin);
	if (game->exit_closed)
		mlx_destroy_image(game->mlx_init, game->exit_closed);
	if (game->exit_opened)
		mlx_destroy_image(game->mlx_init, game->exit_opened);
	if (game->wall)
		mlx_destroy_image(game->mlx_init, game->wall);
	if (game->back)
		mlx_destroy_image(game->mlx_init, game->back);
	if (game->player)
		mlx_destroy_image(game->mlx_init, game->player);
	if (game->mlx_init)
	{
		mlx_destroy_display(game->mlx_init);
		free(game->mlx_init);
	}
	if (game->map)
		split_free(game->map, count_splited(game->map));
}

int	key_code(int key, t_game *game)
{
	if (key == KEY_ESC || key == KEY_Q)
		return (close_window_and_free(game),
			ft_printf(CYAN "You Exit the Game!\n"), exit(0), 0);
	else if (key == KEY_W || key == KEY_UP)
		move_player(game, 0, -1);
	else if (key == KEY_S || key == KEY_DOWN)
		move_player(game, 0, 1);
	else if (key == KEY_D || key == KEY_RIGHT)
		move_player(game, 1, 0);
	else if (key == KEY_A || key == KEY_LEFT)
		move_player(game, -1, 0);
	return (0);
}

void	print_win_message(void)
{
	printf("\n");
	printf(GREEN "╔════════════════════════════╗\n");
	printf(GREEN "║" GREEN "   CONGRATULATIONS!   " GREEN "║\n");
	printf(GREEN "║" GREEN "     YOU WON!        " GREEN "║\n");
	printf(GREEN "╚════════════════════════════╝\n\n");
	printf(RESET);
}
