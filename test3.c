/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:15:37 by trpham            #+#    #+#             */
/*   Updated: 2024/11/28 13:31:18 by trpham           ###   ########.fr       */
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

	fd = open("not_exist.txt", O_RDONLY);
	count = 0;
	while (1)
	{
		nextline = get_next_line(fd);
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
