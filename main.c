/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:07:59 by trpham            #+#    #+#             */
/*   Updated: 2024/11/28 11:16:45 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

void	test1(void);
void	test2(void);

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Input test number: \n");
		return (1);
	}
	if (strcmp(argv[1], "1") == 0)
		test1();
	else if (strcmp(argv[1], "2") == 0)
		test2();
	else if (strcmp(argv[1], "3") == 0)
		test2();
	else
		printf("Invalid test number! \n");
	return (0);
}