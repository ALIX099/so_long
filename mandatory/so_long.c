/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 06:57:21 by abouknan          #+#    #+#             */
/*   Updated: 2025/04/04 07:57:18 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_destroy(int keycode ,t_game *game)
{
	(void)keycode;
		mlx_destroy_display(game->mlx_init);
		free(game->mlx_init);
	if (game->map)
		split_free(game->map, count_splited(game->map));
	exit(0);
	return (0);
}
int	main(int ac, char **av)
{
	int		w;
	int		h;
	t_game	game;

	w = 64;
	h = 64;
	if (ac != 2 || !ber_parsing(av[1]))
		return (write(2, RED "Error\nIncorrect Args Or Map File Is Wrong !\n",
				45), 1);
	load_map(&game, av[1]);
	check_map(&game);
	check_accesses(&game);
	init_mlx(&game, w, h);
	put_image_in_map(&game);
	mlx_key_hook(game.mlx_win, key_code, &game);
	mlx_hook(game.mlx_win, 17, 0, &handle_destroy, &game);
	mlx_loop(game.mlx_init);
}
