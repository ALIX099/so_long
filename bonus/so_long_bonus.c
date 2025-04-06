/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:19:00 by abouknan          #+#    #+#             */
/*   Updated: 2025/04/06 14:00:31 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	animation_loop(t_game *game)
{
	game->frame_count++;
	if (game->frame_count >= 10000)
	{
		game->killer_frame = (game->killer_frame + 1) % 5;
		move_enemies(game);
		game->frame_count = 0;
	}
	return (0);
}

void	ft_mouve_count(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->move_count + 1);
	mlx_set_font(game->mlx_init, game->mlx_win, "rk24");
	mlx_put_image_to_window(game->mlx_init, game->mlx_win, game->back, 60,
		game->map_y * 40);
	mlx_put_image_to_window(game->mlx_init, game->mlx_win, game->back, 92,
		game->map_y * 40);
	mlx_put_image_to_window(game->mlx_init, game->mlx_win, game->back, 124,
		game->map_y * 40);
	mlx_string_put(game->mlx_init, game->mlx_win, 2, game->map_y * 40 + 30,
		0x557D55, "Move: ");
	mlx_string_put(game->mlx_init, game->mlx_win, 60, game->map_y * 40 + 30,
		0x557D55, moves);
	free(moves);
}

int	handle_destroy(t_game *game)
{
	close_window_and_free(game);
	ft_printf(CYAN "You Exit the Game!\n");
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;
	int		w;
	int		h;

	w = 40;
	h = 40;
	game.frame_count = 0;
	game.killer_frame = 0;
	game.move_count = 0;
	if (ac != 2 || !ber_parsing(av[1]))
		return (write(2, RED "Error\nIncorrect Args Or Map File Is Wrong!\n",
				50), 1);
	load_map(&game, av[1]);
	game.enemy_seed = 1;
	check_map(&game);
	check_accesses(&game);
	init_mlx(&game, w, h);
	put_image_in_map(&game);
	mlx_hook(game.mlx_win, 2, 1L << 0, key_code, &game);
	mlx_hook(game.mlx_win, 17, 0, handle_destroy, &game);
	mlx_loop_hook(game.mlx_init, animation_loop, &game);
	mlx_loop(game.mlx_init);
}
