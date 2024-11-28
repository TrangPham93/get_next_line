/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:15:37 by trpham            #+#    #+#             */
/*   Updated: 2024/11/28 11:17:28 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	test3(void)

{
	char	*nextline;
	int		fd;
	int		count;

	// Create an open file description that refers to a file and 
	// a file descriptor that refers to that open file description
	fd = open("not exist", O_RDONLY);
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
			printf("EOF! Could not get next line\n");
			break ;
		}
		count++;
		printf("return line [%d]:%s\n", count, nextline);
		free(nextline);	
	}
	close(fd);
}