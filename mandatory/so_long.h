/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 21:54:26 by abouknan          #+#    #+#             */
/*   Updated: 2025/04/04 05:55:39 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../includes/.minilibx-linux/mlx.h"
# include "../includes/ft_printf/ft_printf.h"
# include "../includes/get_next_line/get_next_line_bonus.h"
# include "../includes/libft/libft.h"

# define RED "\033[1;31m"
# define CYAN "\033[1;96m"
# define GREEN "\033[0;32m"

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

# define KEY_Q 113
# define KEY_ESC 65307

typedef struct s_game
{
	void	*wall;
	void	*back;
	void	*exit_opened;
	void	*exit_closed;
	void	*player;
	void	*coin;
	char	*addr;
	void	*mlx_init;
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
int			count_splited(char **str);
void		check_map_y(t_game *game);
void		check_map_x(t_game *game);
void		check_newline(char *map);
void		check_accesses(t_game *game);
void		get_e_x_e_y(t_game *game);
void		init_mlx(t_game *game, int w, int h);
void		error_handling(char *message, t_game *game);
void		put_in_map(t_game *game, char c, int x, int y);
void		put_image_in_map(t_game *game);
int			key_code(int key, t_game *game);
void		move_player(t_game *game, int x, int y);
void		close_window_and_free(t_game *game);

#endif