/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:32:14 by trpham            #+#    #+#             */
/*   Updated: 2024/11/28 16:27:57 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
/* 

Here's why they appear to be treated similarly:

    For a null pointer: Dereferencing a null pointer is undefined behavior, 
but many implementations treat it as if it points to a null byte, 
making !*main_buffer evaluate to true.
    For an empty string: The first (and only) character of an empty string 
is the null terminator, so !*main_buffer also evaluates to true. 
*/

char	*read_file(char *buffer, int fd);
char	*extract_line(char	*buffer);
char	*extract_remaining(char *buffer);

char	*get_next_line(int fd)
{
	static char	*main_buffer = NULL;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(main_buffer), NULL);
	if (!main_buffer)
		main_buffer = ft_calloc(1, sizeof(char));
	if (!main_buffer)
		return (NULL);
	if (!ft_strchr(main_buffer, '\n'))
	{
		temp = read_file(main_buffer, fd);
		if (!temp)
			return (free(main_buffer), free(temp), NULL); //add free
		free(main_buffer);
		main_buffer = temp;
	}
	if (main_buffer == NULL || *main_buffer == '\0')
		return (free(main_buffer), NULL);
	line = extract_line(main_buffer);
	if (!line)
		return (free(main_buffer), free(line), NULL); // add free
	temp = extract_remaining(main_buffer);
	if (!temp)
		return (free(main_buffer), free(temp), line); // add free
	free(main_buffer);
	main_buffer = temp;
	return (line);
}

char	*read_file(char *buffer, int fd)
{
	ssize_t	bytes_read;
	char	*read_buffer;

	read_buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!read_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(read_buffer), NULL);
		read_buffer[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, read_buffer);
		if (!buffer)
			return (free(read_buffer), free(buffer), NULL); // add free
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

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	line = ft_substr(buffer, 0, i);
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
