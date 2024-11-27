/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:37:33 by trpham            #+#    #+#             */
/*   Updated: 2024/11/27 11:18:00 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*nextline;
	int		fd;
	int		count;

	// Create an open file description that refers to a file and 
	// a file descriptor that refers to that open file description
	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error! Could not open file\n");
		exit (-1);
	}
	count = 0;
	while (1)
	{
		nextline = get_next_line(fd);
		// if (!nextline)
		// 	break ;
		if (!nextline)
		{
			printf("Error! Could not get line\n");
			return (free(nextline), -1);
		}
		count++;
		printf("return line [%d]:%s\n", count, nextline);
		free(nextline);	
	}
	close(fd);
	return (0);
}