/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ber_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 01:07:23 by abouknan          #+#    #+#             */
/*   Updated: 2025/04/07 22:40:57 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**split_free(char **s, int i);
int		count_splited(char **str);

int	ber_parsing(char *str)
{
	char	*filename;
	int		len;

	if (!str)
		return (0);
	filename = str;
	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	if (filename[len - 1] == 'r' && filename[len - 2] == 'e' && filename[len
			- 3] == 'b' && filename[len - 4] == '.' && str[len - 5] != '/')
		return (1);
	return (0);
}

void	check_map_y(t_game *game)
{
	int	i;

	i = 0;
	if (game->map_y > 100)
		return (split_free(game->map, count_splited(game->map)),
			ft_printf(RED "Error\nYou Passed the Map Limit\n"), exit(1));
	while (i < game->map_y)
	{
		if (ft_strlen(game->map[i]) != ft_strlen(game->map[0]))
			return (ft_printf(RED "Error\nMap Walls!\n"), split_free(game->map,
					count_splited(game->map)), exit(1));
		if (game->map[i][0] != '1' || game->map[i][ft_strlen(game->map[0])
			- 1] != '1')
			return (ft_printf(RED "Error\nMap Walls!\n"), split_free(game->map,
					count_splited(game->map)), exit(1));
		i++;
	}
}

void	check_map_x(t_game *game)
{
	int	i;

	i = 0;
	game->map_x = ft_strlen(game->map[0]);
	if (game->map_x > 100)
		return (split_free(game->map, count_splited(game->map)),
			ft_printf(RED "Error\nYou Passed the Map Limit\n"), exit(1));
	while (i < game->map_x)
	{
		if (game->map[0][i] != '1' || game->map[game->map_y - 1][i] != '1')
			return (ft_printf(RED "Error\nMap Walls!\n"), split_free(game->map,
					count_splited(game->map)), exit(1));
		i++;
	}
}

void	check_newline(char *map)
{
	int	i;

	i = 0;
	if (!map)
		return (ft_printf(RED "Error\nEmpty!\n"), exit(1));
	if (map[0] == '\n')
		return (free(map), ft_printf(RED "Error\nNewline!\n"), exit(1));
	if (map[ft_strlen(map) - 1] == '\n')
	{
		free(map);
		ft_printf(RED "Error\nNewline!\n");
		exit(1);
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_printf(RED "Error\nNewline!\n");
			exit(1);
		}
		i++;
	}
}
