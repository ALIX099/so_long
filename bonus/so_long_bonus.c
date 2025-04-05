/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:19:00 by abouknan          #+#    #+#             */
/*   Updated: 2025/04/05 14:06:31 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_updated_tiles(t_game *data, int *prev_killer_frame)
{
	int	x;
	int	y;

	if (data->killer_frame != *prev_killer_frame)
	{
		y = 0;
		while (y < data->map_y)
		{
			x = 0;
			while (x < data->map_x)
			{
				if (data->map[y][x] == 'T')
					put_in_map(data, 'T', x * 40, y * 40);
				x++;
			}
			y++;
		}
		*prev_killer_frame = data->killer_frame;
	}
}

int	animation_loop(t_game *game)
{
	static int	prev_killer_frame = -1;

	game->frame_count++;
	if (game->frame_count >= 40000)
	{
		game->killer_frame = (game->killer_frame + 1) % 5;
		game->frame_count = 0;
		render_updated_tiles(game, &prev_killer_frame);
	}
	return (0);
}
void	ft_print_movements(t_game *game)
{
	char	*movements;
	// char	*phrase;

	movements = ft_itoa(game->move_count);
	// ft_printf("%s %s", "Movements : ", movements);
	mlx_string_put(game->mlx_init, game->mlx_win, 40, 20, 6000, movements);
	// free(movements);
	// free(phrase);
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
	mlx_loop_hook(game.mlx_init, animation_loop, &game);
	mlx_loop(game.mlx_init);
}
