/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:40:09 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/27 12:49:50 by cnysten          ###   ########.fr       */
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
}
