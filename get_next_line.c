/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:32:14 by trpham            #+#    #+#             */
/*   Updated: 2024/12/02 12:00:08 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(char *buffer, int fd);
char	*extract_line(char	*buffer);
char	*extract_remaining(char *buffer);
char	*update_buffer(char **buffer, int fd);

char	*get_next_line(int fd)
{
	static char	*main_buffer = NULL;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(main_buffer), NULL);
	if (!main_buffer)
	{
		main_buffer = malloc(1);
		main_buffer[0] = 0;
	}
	if (!main_buffer)
		return (NULL);
	update_buffer(&main_buffer, fd);
	if (main_buffer == NULL || *main_buffer == '\0')
		return (NULL);
	line = extract_line(main_buffer);
	if (!line)
		return (free(main_buffer), NULL);
	temp = extract_remaining(main_buffer);
	if (!temp)
		return (free(main_buffer), line);
	free(main_buffer);
	main_buffer = temp;
	return (line);
}

char	*update_buffer(char **buffer, int fd)
{
	char	*temp;

	if (!ft_strchr(*buffer, '\n'))
	{
		temp = read_file(*buffer, fd);
		if (!temp)
			return (NULL);
		*buffer = temp;
	}
	return (*buffer);
}

char	*read_file(char *buffer, int fd)
{
	ssize_t	bytes_read;
	char	*read_buffer;
	char	*tem;

	read_buffer = malloc(BUFFER_SIZE + 1);
	if (!read_buffer)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(read_buffer), NULL);
		read_buffer[bytes_read] = '\0';
		tem = ft_strjoin(buffer, read_buffer);
		if (!tem)
			return (free(read_buffer), NULL);
		free(buffer);
		buffer = tem;
		if (ft_strchr(buffer, '\n'))
			break ;
		if (bytes_read == 0)
			break ;
	}
	free(read_buffer);
	return (buffer);
}

char	*extract_line(char	*buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	while (j <= i)
	{
		line[j] = buffer[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*extract_remaining(char *buffer)
{
	char	*remaining;
	char	*newline_position;

	newline_position = ft_strchr(buffer, '\n');
	if (!newline_position)
		return (ft_strdup(""));
	remaining = ft_strdup(newline_position + 1);
	return (remaining);
}
