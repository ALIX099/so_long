/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:25:07 by abouknan          #+#    #+#             */
/*   Updated: 2025/04/05 10:50:31 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

char		**split_free(char **s, int i);
int			count_splited(char **str);

static void	flood_fill(t_game *game, int x, int y)
{
	char	**map;

	map = game->map;
	if (x < 0 || y < 0 || x >= game->map_x || y >= game->map_y)
		return ;
	if (map[y][x] == 'Q' || map[y][x] == 'E' || map[y][x] == '1'
		|| map[y][x] == 'V' || map[y][x] == 'D' || map[y][x] == 'T')
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
	int	found;

	x = 0;
	y = 0;
	found = 0;
	while (y < game->map_y)
	{
		x = 0;
		while (x < game->map_x)
		{
			if (game->map[y][x] == 'C')
				return (0);
			if (game->map[y][x] == 'Q')
				found = 1;
			x++;
		}
		y++;
	}
	return (found);
}

static void	return_to_init(t_game *game)
{
	int		x;
	int		y;
	char	**map;

	x = 0;
	y = 0;
	map = game->map;
	while (y < game->map_y)
	{
		x = 0;
		while (x < game->map_x)
		{
			if (map[y][x] == 'Q')
				map[y][x] = 'C';
			else if (map[y][x] == 'D')
				map[y][x] = 'P';
			else if (map[y][x] == 'V')
				map[y][x] = '0';
			x++;
		}
		y++;
	}
}

void	check_accesses(t_game *game)
{
	int	result;

	flood_fill(game, game->player_x, game->player_y);
	get_e_x_e_y(game);
	result = check_access_e(game, game->e_x, game->e_y);
	if (!result)
		return (split_free(game->map, count_splited(game->map)),
			ft_printf(RED "Error\nThe Exit is Not accessible\n"), exit(1));
	result = check_access_c(game);
	if (!result)
		return (split_free(game->map, count_splited(game->map)),
			ft_printf(RED "Error\nA Collectible is Not accessible\n"), exit(1));
	return_to_init(game);
}
