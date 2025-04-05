/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:19:00 by abouknan          #+#    #+#             */
/*   Updated: 2025/04/05 12:23:12 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_enemy(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'T')
			{
				game->enemy_x = x;
				game->enemy_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	enemy_move(t_game *game)
{
	int	i;

	i = 0;
	get_enemy(game);
	mlx_put_image_to_window(game->mlx_init, game->mlx_win, game->enemy_two,
		game->enemy_x * 40, game->enemy_y * 40);
		while (i < 50000)
		i++;
	i = 0;
	mlx_put_image_to_window(game->mlx_init, game->mlx_win, game->enemy_three,
		game->enemy_x * 40, game->enemy_y * 40);
	while (i < 50000)
		i++;
	i = 0;
	mlx_put_image_to_window(game->mlx_init, game->mlx_win, game->enemy_one,
		game->enemy_x * 40, game->enemy_y * 40);
	while (i < 50000)
		i++;
	i = 0;
	mlx_put_image_to_window(game->mlx_init, game->mlx_win, game->enemy_four,
		game->enemy_x * 40, game->enemy_y * 40);
	while (i < 50000)
		i++;
	i = 0;
	mlx_put_image_to_window(game->mlx_init, game->mlx_win, game->enemy_five,
		game->enemy_x * 40, game->enemy_y * 40);
	return (0);
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
	mlx_loop_hook(game.mlx_init, enemy_move, &game);
	mlx_loop(game.mlx_init);
}
