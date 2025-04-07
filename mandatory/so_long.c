/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 06:57:21 by abouknan          #+#    #+#             */
/*   Updated: 2025/04/07 22:35:57 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_destroy(t_game *game)
{
	close_window_and_free(game);
	ft_printf(CYAN "You Exit the Game!\n");
	ft_printf(RESET);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	int		w;
	int		h;
	t_game	game;

	w = 40;
	h = 40;
	if (ac != 2 || !ber_parsing(av[1]))
		return (write(2, RED "Error\nIncorrect Args Or Map File Is Wrong!\n",
				50), 1);
	load_map(&game, av[1]);
	check_map(&game);
	check_accesses(&game);
	init_mlx(&game, w, h);
	put_image_in_map(&game);
	mlx_hook(game.mlx_win, 2, 1L << 0, key_code, &game);
	mlx_hook(game.mlx_win, 17, 0, handle_destroy, &game);
	mlx_loop(game.mlx_init);
}
