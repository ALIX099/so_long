/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 01:07:23 by abouknan          #+#    #+#             */
/*   Updated: 2025/04/01 04:44:41 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char		**split_free(char **s, int i);
int			count_splited(char **str);

static char	*extract_filename(char *path)
{
	int	i;
	int	last_slash;

	i = 0;
	last_slash = 0;
	while (path[i])
	{
		if (path[i] == '/' || path[i] == '\\')
			last_slash = i + 1;
		i++;
	}
	return (&path[last_slash]);
}

int	ber_parsing(char *str)
{
	char	*filename;
	int		len;

	if (!str)
		return (0);
	filename = extract_filename(str);
	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	if (filename[len - 1] == 'r' && filename[len - 2] == 'e' && filename[len
		- 3] == 'b' && filename[len - 4] == '.' && filename[len - 5] != ' ')
		return (1);
	return (0);
}

void	check_map_y(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_y)
	{
		if (ft_strlen(game->map[i]) != ft_strlen(game->map[0]))
			return (ft_printf(RED "Error: In Map Walls!\n"),
				split_free(game->map, count_splited(game->map)), exit(1));
		if (game->map[i][0] != '1' || game->map[i][ft_strlen(game->map[0])
			- 1] != '1')
			return (ft_printf(RED "Error: In Map Walls!\n"),
				split_free(game->map, count_splited(game->map)), exit(1));
		i++;
	}
}

void	check_map_x(t_game *game)
{
	int	i;

	i = 0;
	game->map_x = ft_strlen(game->map[0]) - 1;
	while (i < game->map_x)
	{
		if (game->map[0][i] != '1' || game->map[game->map_y - 1][i] != '1')
			return (ft_printf(RED "Error: In Map Walls!\n"),
				split_free(game->map, count_splited(game->map)), exit(1));
		i++;
	}
}

void	check_newline(char *map)
{
	int	i;

	i = 0;
	if (!map)
	{
		ft_printf(RED "Error: Map Is Empty!\n");
		exit(1);
	}
	if (map[ft_strlen(map) - 1] == '\n')
	{
		free(map);
		ft_printf(RED "Error: In Newline!\n");
		exit(1);
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_printf(RED "Error: In Newline!\n");
			exit(1);
		}
		i++;
	}
}
