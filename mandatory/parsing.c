/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 01:07:23 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/31 02:34:32 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*extract_filename(char *path)
{
	int	i;
	int	last_slash;

	i = 0;
	last_slash = 0;
	while (path[i])
	{
		if (path[i] == '/' || path[i] == '\\')
			last_slash = i + 1;
		i++;
	}
	return (&path[last_slash]);
}

int	ber_parsing(char *str)
{
	char *filename;
	int len;

	if (!str)
		return (0);
	filename = extract_filename(str);
	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	if (filename[len - 1] == 'r' && filename[len - 2] == 'e' && filename[len
		- 3] == 'b' && filename[len - 4] == '.' && filename[len - 5] != ' ')
		return (1);
	return (0);
}