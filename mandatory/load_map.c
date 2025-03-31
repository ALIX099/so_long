/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 06:33:35 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/31 07:06:29 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_map(t_game *game, char *filename)
{
	char	*joined_str;
	int		fd;
	char	*line;
	char	*temp;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf(RED "Error: Could not open map file!\n");
		exit(EXIT_FAILURE);
	}
	joined_str = ft_strdup("");
	if (!joined_str)
	{
		ft_printf(RED "Error: allocation failed while loading map\n");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line)
	{
		joined_str = ft_strjoin(joined_str, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	game->map = ft_split(joined_str, '\n');
	free(joined_str);
}

