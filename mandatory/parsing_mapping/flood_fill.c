/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 23:25:27 by abouknan          #+#    #+#             */
/*   Updated: 2025/04/02 05:49:06 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	flood_fill(t_game *game, int x, int y)
{
	char	**map;

	map = game->map;
	if (x < 0 || y < 0 || x >= game->map_x || y >= game->map_y)
		return ;
	if (map[y][x] == 'Q' || map[y][x] == 'E' || map[y][x] == '1'
		|| map[y][x] == 'V' || map[y][x] == 'D')
		return ;
	if (map[y][x] == '0')
		map[y][x] = 'V';
	else if (map[y][x] == 'C')
		map[y][x] = 'Q';
	else if (map[y][x] == 'P')
		map[y][x] = 'D';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}

static int	check_access_e(t_game *game, int e_x, int e_y)
{
	char	**map;

	map = game->map;
	if (map[e_y][e_x + 1] == 'D' || map[e_y][e_x + 1] == 'V' || map[e_y][e_x
		+ 1] == 'Q')
		return (1);
	if (map[e_y][e_x - 1] == 'D' || map[e_y][e_x - 1] == 'V' || map[e_y][e_x
		- 1] == 'Q')
		return (1);
	if (map[e_y + 1][e_x] == 'D' || map[e_y + 1][e_x] == 'V' || map[e_y
		+ 1][e_x] == 'Q')
		return (1);
	if (map[e_y - 1][e_x] == 'D' || map[e_y - 1][e_x] == 'V' || map[e_y
		- 1][e_x] == 'Q')
		return (1);
	return (0);
}

static int	check_access_c(t_game *game)
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
			if (game->map[y][x] == 'C')
				return (0);
			else if ((game->map[y][x] == 'Q') && game->map[y + 1][x] == 'V'
				|| game->map[y - 1][x] == 'V' || game->map[y][x + 1] == 'V'
				|| game->map[y][x - 1] == 'V' || game->map[y + 1][x] == 'Q'
				|| game->map[y - 1][x] == 'Q' || game->map[y][x + 1] == 'Q'
				|| game->map[y][x - 1] == 'Q' || game->map[y + 1][x] == 'D'
				|| game->map[y - 1][x] == 'D' || game->map[y][x + 1] == 'D'
				|| game->map[y][x - 1] == 'D')
				return (1);
		}
	}
	return (0);
}

static void	get_e_x_e_y(t_game *game)
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

void check_accesses(t_game *game)
{
    int result;
    flood_fill(game, player_x, player_y);
    get_e_x_e_y(game);
    result = check_access_e(game, game->e_x, game->e_y);
    if (!result)
        return(split_free(game->map, count_splited(game->map)), ft_printf(RED"The Exit is Not accessible\n"), exit(1));
}