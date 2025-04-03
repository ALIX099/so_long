/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 07:17:52 by abouknan          #+#    #+#             */
/*   Updated: 2025/04/03 11:25:13 by abouknan         ###   ########.fr       */
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
	ft_printf(RED "%s", message);
	return (split_free(game->map, count_splited(game->map)), exit(1));
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
