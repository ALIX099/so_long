/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 03:25:35 by abouknan          #+#    #+#             */
/*   Updated: 2024/12/22 23:15:55 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_and_append(int fd, char *buffer, char *storage)
{
	int		bytes_read;
	char	*temp_storage;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		temp_storage = storage;
		storage = ft_strjoin(temp_storage, buffer);
		if (!storage)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read == -1)
		return (NULL);
	return (storage);
}

static char	*get_line(char **storage)
{
	char	*line;
	char	*new_storage;
	size_t	i;

	if (**storage == '\0')
		return (NULL);
	i = 0;
	while ((*storage)[i] != '\n' && (*storage)[i])
		i++;
	line = ft_substr(*storage, 0, i + ((*storage)[i] == '\n'));
	if (!line)
		return (NULL);
	new_storage = ft_substr(*storage, i + 1, ft_strlen(*storage) - i);
	free(*storage);
	*storage = new_storage;
	if (**storage == '\0')
	{
		free(*storage);
		*storage = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*storage[1024];
	char		*buffer;
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0 || fd == 1 || fd == 2)
		return (NULL);
	buffer = (char *)malloc((size_t)(BUFFER_SIZE) + 1);
	if (!buffer)
		return (NULL);
	storage[fd] = read_and_append(fd, buffer, storage[fd]);
	free(buffer);
	if (!storage[fd])
		return (NULL);
	line = get_line(&storage[fd]);
	return (line);
}
