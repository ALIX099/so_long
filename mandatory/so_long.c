/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 06:57:21 by abouknan          #+#    #+#             */
/*   Updated: 2025/04/02 07:08:13 by abouknan         ###   ########.fr       */
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
	check_accesses(&game);
	// check the file name map .ber and texture .xpm
	// open the window using h and w
	// put your images in the window using mlx functions like mlx_put_image
	// your design and setting movment of the player and enemy
	// free the resources and destroy the window
	// finish
	return (0);
}
