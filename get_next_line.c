/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:32:14 by trpham            #+#    #+#             */
/*   Updated: 2024/11/26 14:56:06 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *read_file(char *buffer, int	fd);
char	*extract_line(char	*buffer);

char	*get_next_line(int	fd)
{
	// ssize_t	bytes_read;
	static char	*main_buffer;
	char	*line;
	
	if (!main_buffer)
		main_buffer = ft_calloc(1, sizeof(char));
	if (!ft_strchr(main_buffer, '\n'))
		main_buffer = read_file(main_buffer, fd);
	if (!main_buffer) // EOF, reading error or calloc fail
		return(free(main_buffer), NULL);
	line = extract_line(main_buffer);
	main_buffer = ft_strchr(main_buffer, '\n') + 1;
	return (line);
}

char	*read_file(char *buffer, int	fd)
{
	ssize_t	bytes_read;
	char	*read_buffer;
	char *temp;
	static int	count = 1;

	printf("ft_calloc [%d]: ", count++);
	read_buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!read_buffer)
		return (free(read_buffer) , NULL);
	bytes_read = 1;
	while (bytes_read > 0) // 0 EOF & -1  reading error
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read <= 0) 
			return (free(read_buffer), NULL);
		temp = ft_strjoin(buffer, read_buffer);
		if (!temp)
			return (free(temp), NULL);
		if (ft_strchr(temp, '\n'))
			break;
	}
	free(read_buffer);
	free(buffer);
	return (temp);
}
char	*extract_line(char	*buffer)
{
	char	*line;
	char	i;

	// line = ft_calloc();
	i = 0;
	while (*buffer != '\n')
		i++;
	if (i == 0)
		return (buffer);
	line = ft_substr(buffer, 0, i + 1);
	return (line);
}
