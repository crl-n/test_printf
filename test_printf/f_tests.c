/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_tests.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 22:04:06 by carlnysten        #+#    #+#             */
/*   Updated: 2022/01/27 22:57:32 by carlnysten       ###   ########.fr       */
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

	restore_stdout(saved_stdout, fd);
	if (compare_output())
		printf("✔︎ Holy shit that's precise\n");
	else
		printf("× Precision doesn't work well\n");

}
