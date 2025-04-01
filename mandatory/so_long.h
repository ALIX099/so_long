/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 21:54:26 by abouknan          #+#    #+#             */
/*   Updated: 2025/04/01 04:30:33 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../includes/ft_printf/ft_printf.h"
# include "../includes/get_next_line/get_next_line_bonus.h"
# include "../includes/libft/libft.h"
# include "../includes/minilibx-linux/mlx.h"

# define RED "\033[1;31m"

typedef struct s_game
{
	void	*img;
	void	*wall;
	void	*back;
	void	*exit;
	void	*player;
	void	*coin;
	char	*addr;
	void	*mlx;
	void	*mlx_win;
	char	**map;
	int		player_x;
	int		e_y;
	int		e_x;
	int		player_y;
	int		collectible_count;
	int		exit_count;
	int		move_count;
	int		map_x;
	int		map_y;
	int		player_n;
}			t_game;

int			ber_parsing(char *str);
void		load_map(t_game *game, char *filename);
void		check_map(t_game *game);
void		check_map_y(t_game *game);
void		check_map_x(t_game *game);
void		check_newline(char *map);

#endif