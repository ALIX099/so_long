/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helper_two_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 07:36:36 by abouknan          #+#    #+#             */
/*   Updated: 2025/04/05 17:51:23 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	reach_empty_or_coin(t_game *game, int new_x, int new_y, char *move_name)
{
	if (game->map[new_y][new_x] != 'C' && game->map[new_y][new_x] != '0')
		return (1);
	if (game->map[new_y][new_x] == 'C')
		game->collectible_count--;
	game->map[game->player_y][game->player_x] = '0';
	put_in_map(game, '0', game->player_x * 40, game->player_y * 40);
	game->player_y = new_y;
	game->player_x = new_x;
	game->map[new_y][new_x] = 'P';
	if (!ft_strcmp(move_name, "UP"))
		mlx_put_image_to_window(game->mlx_init, game->mlx_win, game->player_up,
			new_x * 40, new_y * 40);
	else if (!ft_strcmp(move_name, "LEFT"))
		mlx_put_image_to_window(game->mlx_init, game->mlx_win,
			game->player_left, new_x * 40, new_y * 40);
	else if (!ft_strcmp(move_name, "DOWN"))
		mlx_put_image_to_window(game->mlx_init, game->mlx_win,
			game->player_down, new_x * 40, new_y * 40);
	else if (!ft_strcmp(move_name, "RIGHT"))
		mlx_put_image_to_window(game->mlx_init, game->mlx_win,
			game->player_right, new_x * 40, new_y * 40);
	if (game->collectible_count == 0)
		mlx_put_image_to_window(game->mlx_init, game->mlx_win,
			game->exit_opened, game->e_x * 40, game->e_y * 40);
	return (ft_mouve_count(game), ft_printf("%d : Move\n", ++game->move_count));
}

void	reach_enemy(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'T')
	{
		ft_mouve_count(game);
		ft_printf("%d : Move\n", ++game->move_count);
		close_window_and_free(game);
		print_lose_message();
		exit(1);
	}
}

void	print_win_message(void)
{
	printf("\n");
	printf(GREEN "╔════════════════════════════╗\n");
	printf(GREEN "║" GREEN "   CONGRATULATIONS!   " GREEN "║\n");
	printf(GREEN "║" GREEN "     YOU WON!        " GREEN "║\n");
	printf(GREEN "╚════════════════════════════╝\n\n");
	printf(RESET);
}

void	print_lose_message(void)
{
	printf("\n");
	printf(RED "╔════════════════════════════╗\n");
	printf(RED "║        💀 GAME OVER 💀       ║\n");
	printf(RED "║         YOU LOST...        ║\n");
	printf(RED "╚════════════════════════════╝\n\n");
	printf("%s", RESET);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
