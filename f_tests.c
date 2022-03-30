/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_tests.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 22:04:06 by carlnysten        #+#    #+#             */
/*   Updated: 2022/02/14 22:15:59 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_printf.h"
#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void	f_tests(void)
{
	int		fd;
	int		saved_stdout;
	char	*format;
	int		i;

	printf(CYAN"\n🔥☠️ 🔥 f-conversion 🔥☠️ 🔥\n"RESET);
	fflush(NULL);

	/* Basic input */
	if (redirect_stdout("output", &saved_stdout, &fd) < 0)
		return ;
	ft_printf("%f\n", 1234.56789);
	printf("%f\n", 1234.56789);
	fflush(NULL);

	restore_stdout(saved_stdout, fd);
	if (compare_output())
		printf("✔︎ Works with basic input\n");
	else
		printf("× Doesn't work with basic input\n");

	/* Precision tests */
	if (redirect_stdout("output", &saved_stdout, &fd) < 0)
		return ;
	
	format = strdup("%.0f\n");
	i = 0;
	while (i < 9)
	{
		ft_printf(format, 1234567.123456789123456789);
		printf(format, 1234567.123456789123456789);
		fflush(NULL);
		format[2]++;
		i++;
	}
	free(format);
	
	format = strdup("%.10f\n");
	i = 0;
	while (i < 9)
	{
		ft_printf(format, 1234567.123456789123456789);
		printf(format, 1234567.123456789123456789);
		fflush(NULL);
		format[3]++;
		i++;
	}
	free(format);

	ft_printf("%.19f\n", 9.9999999999999999999999999);
	printf("%.19f\n", 9.9999999999999999999999999);

	ft_printf("%.f %.f %.f", 0.5, 1.5, 2.5);
	printf("%.f %.f %.f", 0.5, 1.5, 2.5);
	fflush(NULL);

	restore_stdout(saved_stdout, fd);
	if (compare_output())
		printf("✔︎ Holy shit that's precise\n");
	else
		printf("× Precision doesn't work well\n");

	/* Combination tests */
	if (redirect_stdout("output", &saved_stdout, &fd) < 0)
		return ;
	
	ft_printf("%15f\n", 1.23);
	printf("%15f\n", 1.23);

	ft_printf("{%#- 10.5f}\n", 12.34);
	printf("{%#- 10.5f}\n", 12.34);
	fflush(NULL);

	restore_stdout(saved_stdout, fd);
	if (compare_output())
		printf("✔︎ Float conversion works with flags and field width\n");
	else
		printf("× Float conversion doesn't work in combination with flags and/or field width\n");
}
