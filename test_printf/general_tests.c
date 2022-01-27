/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:40:09 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/27 23:55:02 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_printf.h"
#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void	general_tests(void)
{
	int		fd;
	int		saved_stdout;
	char	*str = strdup("bcdef");

	printf(CYAN"\ngeneral tests\n"RESET);
	fflush(NULL);

	/* Test multiple conversions of different type */
	if (redirect_stdout("output", &saved_stdout, &fd) < 0)
		return ;
	ft_printf("%c%s%p%d%i%o%u%x%X%f\n", 'a', str, str, 123, 456, 9, 11, 0xf, 0xf, 111.0);
	printf("%c%s%p%d%i%o%u%x%X%f\n", 'a', str, str, 123, 456, 9, 11, 0xf, 0xf, 111.0);
	fflush(NULL);
	restore_stdout(saved_stdout, fd);
	if (compare_output())
		printf("✔︎ Works with multiple conversions of different types\n");
	else
		printf("× Doesn't work well with multiple conversions of different types\n");

	/* Test empty format string */
	if (redirect_stdout("output", &saved_stdout, &fd) < 0)
		return ;
	ft_printf("");
	printf("\n");
	printf("");
	printf("\n");
	fflush(NULL);

	restore_stdout(saved_stdout, fd);
	if (compare_output())
		printf("✔︎ Parser can handle empty format string\n");
	else
		printf("× Parser can't handle empty format string\n");


	/* Test %% */
	if (redirect_stdout("output", &saved_stdout, &fd) < 0)
		return ;
	ft_printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
	printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
	fflush(NULL);

	restore_stdout(saved_stdout, fd);
	if (compare_output())
		printf("✔︎ Parser can handle %%%%\n");
	else
		printf("× Parser can't handle %%%%\n");

	/* Multiple directives with multiple flags and %% */
	if (redirect_stdout("output", &saved_stdout, &fd) < 0)
		return ;

	ft_printf("%15scspdiouxXf%-15s\n", "abc", "def");
	printf("%15scspdiouxXf%-15s\n", "abc", "def");
	fflush(NULL);

	ft_printf("%% %%%1iiii%+0i1 %001i- #+i%011i- #%%%%\n", 123, 456, 789, 0);
	printf("%% %%%1iiii%+0i1 %001i- #+i%011i- #%%%%\n", 123, 456, 789, 0);
	fflush(NULL);

	restore_stdout(saved_stdout, fd);
	if (compare_output())
		printf("✔︎ Parser can handle complicated input\n");
	else
		printf("× Parser can't handle complicated input\n");
}
