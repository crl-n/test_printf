/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:08:45 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/27 12:50:12 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_printf.h"
#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void	c_tests(void)
{
	int		fd;
	int		saved_stdout;
	char	c;

	printf(CYAN"\nc-conversion\n"RESET);
	fflush(NULL);

	/* Test all printable ascii chars */
	if (redirect_stdout("output", &saved_stdout, &fd) < 0)
		return ;
	c = 32;
	while (1)
	{
		ft_printf("%c\n", c);
		printf("%c\n", c);
		fflush(NULL);
		if (c == 127)
			break ;
		c++;
	}
	restore_stdout(saved_stdout, fd);
	if (compare_output())
		printf("✔︎ Works with all printable ascii characters\n");
	else
		printf("× Doesn't work with all printable ascii characters\n");

	/* Test several c-conversions */
	if (redirect_stdout("output", &saved_stdout, &fd) < 0)
		return ;
	ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z');
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z');
	fflush(NULL);

	restore_stdout(saved_stdout, fd);
	if (compare_output())
		printf("✔︎ Works with multiple c-conversions\n");
	else
		printf("× Doesn't work well with multiple c-conversions\n");
}

void	s_tests(void)
{
	int		fd;
	int		saved_stdout;
	char	*s1 = strdup("hello world");

	printf(CYAN"\ns-conversion\n"RESET);
	fflush(NULL);

	if (redirect_stdout("output", &saved_stdout, &fd) < 0)
		return ;
	ft_printf("%s\n", s1);
	printf("%s\n", s1);
	fflush(NULL);
	ft_printf("%s\n", "buu");
	printf("%s\n","baa");
	fflush(NULL);
	restore_stdout(saved_stdout, fd);
	free(s1);
	if (compare_output())
		return ;
}

void	p_tests(void)
{
	int		fd;
	int		saved_stdout;
	char	*s1 = strdup("hello world");

	printf(CYAN"\np-conversion\n"RESET);
	fflush(NULL);

	if (redirect_stdout("output", &saved_stdout, &fd) < 0)
		return ;
	ft_printf("%p\n", s1);
	printf("%p\n", s1);
	fflush(NULL);
	restore_stdout(saved_stdout, fd);
	free(s1);
	if (compare_output())
		return ;
}
