/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_tests.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 22:04:06 by carlnysten        #+#    #+#             */
/*   Updated: 2022/01/27 22:58:24 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_printf.h"
#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void	i_tests(void)
{
	int		fd;
	int		saved_stdout;
	int		i;

	printf(CYAN"\ni-conversion\n"RESET);
	fflush(NULL);

	/* Basic input */
	if (redirect_stdout("output", &saved_stdout, &fd) < 0)
		return ;
	
	ft_printf("%i\n", 0);
	printf("%i\n", 0);
	fflush(NULL);

	i = -10000;
	while (i < 10000)
	{
		ft_printf("%i\n", i);
		printf("%i\n", i);
		fflush(NULL);
		i += 9876;
	}
	restore_stdout(saved_stdout, fd);
	if (compare_output())
		printf("✔︎ Works with basic input\n");
	else
		printf("× Doesn't work with basic input\n");

	if (redirect_stdout("output", &saved_stdout, &fd) < 0)
		return ;

	/* Max and min int */
	ft_printf("%i\n", 2147483647);
	printf("%i\n", 2147483647);
	fflush(NULL);

	ft_printf("%i\n", -2147483647);
	printf("%i\n", -2147483647);
	fflush(NULL);

	restore_stdout(saved_stdout, fd);
	if (compare_output())
		printf("✔︎ Works with max and min int\n");
	else
		printf("× Doesn't work with max and min int\n");
}
