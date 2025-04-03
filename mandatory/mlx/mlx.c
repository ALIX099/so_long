/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 02:00:54 by abouknan          #+#    #+#             */
/*   Updated: 2025/04/03 06:57:30 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_mlx(t_game *game, int w, int h)
{
	game->mlx_init = mlx_init();
	if (!game->mlx_init)
		return (error_handling("Mlx Can't be initialized!\n", game));
	game->mlx_win = mlx_new_window(game->mlx_init, game->map_x * 32, game->map_y
			* 32, "so_long");
	if (!game->mlx_win)
	{
		free(game->mlx_init);
		return (error_handling("Mlx Can't be initialized!\n", game));
	}
	game->coin = mlx_xpm_to_image(game->mlx_init, "textures/", &w, &h);
	game->img = mlx_xpm_to_image(game->mlx_init, "textures/", &w, &h);
	game->player = mlx_xpm_to_image(game->mlx_init, "textures/", &w, &h);
	game->exit_closed = mlx_xpm_to_image(game->mlx_init, "textures/", &w, &h);
	game->exit_opened = mlx_xpm_to_image(game->mlx_init, "textures/", &w, &h);
	game->wall = mlx_xpm_to_image(game->mlx_init, "textures/", &w, &h);
	game->back = mlx_xpm_to_image(game->mlx_init, "textures/", &w, &h);
	if (!game->coin || !game->img || !game->player || !game->exit_closed
		|| !game->exit_opened || !game->wall || !game->back)
		return (free(game->mlx_init), free(game->mlx_win),
			error_handling("Error : While xpm to image", game));
}
