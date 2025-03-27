/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fionni <fionni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:44:02 by fionni            #+#    #+#             */
/*   Updated: 2025/03/27 15:44:02 by fionni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = read_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	buffer = clean_buffer(buffer);
	return (line);
}

char	*read_buffer(int fd, char *buffer)
{
	char	*temp_buffer;
	int		size;

	temp_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp_buffer)
		return (NULL);
	size = 1;
	while (!(ft_strchr(buffer, '\n')) && size > 0)
	{
		size = read(fd, temp_buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(temp_buffer);
			return (NULL);
		}
		temp_buffer[size] = '\0';
		buffer = ft_strjoin(buffer, temp_buffer);
	}
	free(temp_buffer);
	return (buffer);
}

char	*extract_line(char *buffer)
{
	char	*line;
	size_t	l_len;

	l_len = 0;
	if (!buffer[l_len])
		return (NULL);
	while (buffer[l_len] && buffer[l_len] != '\n')
		l_len++;
	if (buffer[l_len] == '\n')
		l_len++;
	line = (char *)malloc(sizeof(char) * (l_len + 1));
	if (!line)
		return (NULL);
	ft_strncpy(line, buffer, l_len);
	line[l_len] = '\0';
	return (line);
}

char	*clean_buffer(char *buffer)
{
	char	*new_buffer;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!new_buffer)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}
