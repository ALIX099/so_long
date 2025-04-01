/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 06:57:21 by abouknan          #+#    #+#             */
/*   Updated: 2025/04/01 01:46:50 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2 || !ber_parsing(av[1]))
		return (write(2, RED "Incorrect Args Or Map File Is Wrong !\n", 45), 1);
	load_map(&game, av[1]);
	check_map(&game);
	// check the file name map .ber and texture .xpm
	// check the file permission using open function .ber and .xpm and clossiha
	// get the width and the hight of this map by reading the map using gnl
	// check the map if valid (characters : 1 0 P E C)
	// open the window using h and w
	// put your images in the window using mlx functions like mlx_put_image
	// your design and setting movment of the player and enemy
	// free the resources and destroy the window
	// finish
	return (0);
}
