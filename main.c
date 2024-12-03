/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:07:59 by trpham            #+#    #+#             */
/*   Updated: 2024/12/03 10:23:12 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

void	test1(void);
void	test2(void);
void	test3(void);

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("INPUT TEST NUMBER: \n");
		return (1);
	}
	if (strcmp(argv[1], "1") == 0)
		test1();
	else if (strcmp(argv[1], "2") == 0)
		test2();
	else if (strcmp(argv[1], "3") == 0)
		test3();
	else
		printf("INVALID TEST NUMBER! \n");
	return (0);
}
