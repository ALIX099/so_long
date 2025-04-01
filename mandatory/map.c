/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 06:33:35 by abouknan          #+#    #+#             */
/*   Updated: 2025/04/01 02:46:07 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**split_free(char **s, int i);
static int		count_chars(char **map, char c);
static int		is_valid_map(char **map);

int	count_splited(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	load_map(t_game *game, char *name)
{
	char	*joined_str;
	int		fd;
	char	*line;

	game->map_x = 0;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (ft_printf(RED "Error: Could not open map file!\n"), exit(1));
	joined_str = NULL;
	line = get_next_line(fd);
	while (line)
	{
		joined_str = ft_strjoin(joined_str, line);
		free(line);
		game->map_x++;
		line = get_next_line(fd);
	}
	close(fd);
	game->map = ft_split(joined_str, '\n');
	free(joined_str);
	if (!game->map || game->map[0] == NULL)
		exit(ft_printf(RED "Error: Map Is Empty Or Invalid!\n"));
	game->map_y = ft_strlen(game->map[0]) - 1;
}

void	check_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->exit_count = count_chars(game->map, 'E');
	game->collectible_count = count_chars(game->map, 'C');
	game->player_n = count_chars(game->map, 'P');
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j; 
				game->player_y = i;
			}
			j++;
		}
		i++;
	}
	if (!is_valid_map(game->map) || game->exit_count != 1 || game->player_n != 1
		|| game->collectible_count < 1)
		return (split_free(game->map, count_splited(game->map)),
			ft_printf(RED "Invalid Map!\n"), exit(1));
}

static int	count_chars(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static int	is_valid_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != 'P'
				&& map[i][j] != '1' && map[i][j] != '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
