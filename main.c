/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:07:59 by trpham            #+#    #+#             */
/*   Updated: 2024/12/03 17:10:24 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

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
	// while ((nextline = get_next_line(fd)) != NULL)
	// {
	// 	printf("%s", nextline);
	// 	free(nextline);
	// }
	int		count;
	count = 0;
	while (count < 7)
	{
		nextline = get_next_line(fd);
		count++;
		printf("return line [%d]:%s\n", count, nextline);
		free(nextline);
	}
	close(fd);
}
