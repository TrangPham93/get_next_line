/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_update.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:32:14 by trpham            #+#    #+#             */
/*   Updated: 2025/03/13 17:53:59 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>
#include <stdio.h>

static void	read_buffer_size_to_main_buffer(char *main_buffer, int fd);
static void	extract_new_main_buffer(char *main_buffer);
char		*extract_line(char	*buffer);


char	*get_next_line(int fd)
{
	static char	main_buffer[MAX_BUFFER];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
	while (ft_strchr(main_buffer, '\n') == NULL)
	{
		read_buffer_size_to_main_buffer(main_buffer, fd);
		// printf("%s", main_buffer);
		if (main_buffer[0] == '\0')
			return (NULL);
	}
	line = extract_line(main_buffer);
	if (!line)
		return (NULL);
	printf("%s", line);
	extract_new_main_buffer(main_buffer);
	printf("%s\n", main_buffer);
	return (line);
}
	
static void	read_buffer_size_to_main_buffer(char *main_buffer, int fd)
{
	ssize_t	bytes_read;
	char	*read_buffer;
	int		i;
	int		j;

	read_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!read_buffer)
		return ;
	bytes_read = read(fd, read_buffer, BUFFER_SIZE);
	if (bytes_read == -1 || bytes_read == 0)
	{
		free(read_buffer);
		return ;
	}
	read_buffer[bytes_read] = '\0';
	i = 0;
	while (main_buffer[i] && i < MAX_BUFFER)
		i++;
	j = 0;
	while (read_buffer[j] && i < MAX_BUFFER)
	{
		main_buffer[i++] = read_buffer[j++];
	}
	free(read_buffer);
	// read_buffer = NULL;
	// return (main_buffer);
}

char	*extract_line(char	*main_buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (main_buffer[i] != '\n' && main_buffer[i] != '\0')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	while (j <= i)
	{
		line[j] = main_buffer[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static void	extract_new_main_buffer(char *main_buffer)
{

	int		i;
	int		j;
	// int		len;

	i = 0;
	j = 0;
	
	while (main_buffer[i] != '\n' && main_buffer[i] != '\0')
	{
		i++;
	}
	while (main_buffer[i])
	{
		main_buffer[j++] = main_buffer[i++];
	}
	main_buffer[j] = '\0';
}

int	main(int argc, char *argv[])
{
	char	*nextline;
	int		fd;

	if (argc != 2)
	{
		printf("INPUT TEST NUMBER: \n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error! Could not open file\n");
		exit (-1);
	}
	while ((nextline = get_next_line(fd)) != NULL)
	{
		printf("%s", nextline);
		free(nextline);
	}
	// int		count;
	// count = 0;
	// while (count < 7)
	// {
	// 	if (count == 2)
	// 	{
	// 		nextline = NULL;
	// 		close(fd);
	// 	}
	// 	else
	// 		nextline = get_next_line(fd);
	// 	count++;
	// 	printf("return line [%d]:%s\n", count, nextline);
	// 	free(nextline);
	// }
	close(fd);
}