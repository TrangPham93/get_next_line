/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:32:14 by trpham            #+#    #+#             */
/*   Updated: 2024/11/25 17:39:29 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putstr(char *s);

char	*get_next_line(int	fd)
{
	ssize_t	bytes_read;
	static char	*buffer;
	int	i_buffer;
	int	i_line;
	char	*line = "";

	buffer = malloc((BUFFER_SIZE ) + 1);
	if (!buffer)
		return (0);
	i_buffer = 0;
	i_line = 0;
	bytes_read = -1;
	while (bytes_read) // ==0 end of file
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1) // error in reading
			return (NULL);
		buffer[bytes_read] = '\0';
		if (buffer[i_buffer] && buffer[i_buffer] == '\n')
		{
			ft_putstr(line);
			i_line = 0;
		}
		else
		{
			line[i_line] = buffer[i_buffer];
			i_buffer++;
			i_line++;
		}
		
	}
	// buffer[bytes_read] = '\0';
	// free(buffer);
	return (buffer);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}