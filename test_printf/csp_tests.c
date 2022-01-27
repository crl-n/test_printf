/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:08:45 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/27 11:26:43 by cnysten          ###   ########.fr       */
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
	int	fd;
	int	saved_stdout;

	printf(CYAN"Testing c-conversion\n"RESET);
	fflush(NULL);

	if (redirect_stdout("output", &saved_stdout, &fd) < 0)
		return ;
	ft_printf("%c\n", 'a');
	printf("%c\n", 'a');
	fflush(NULL);
	restore_stdout(saved_stdout, fd);
	if (compare_output())
		return ;
}

void	s_tests(void)
{
	int		fd;
	int		saved_stdout;
	char	*s1 = strdup("hello world");

	printf(CYAN"Testing s-conversion\n"RESET);
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

	printf(CYAN"Testing p-conversion\n"RESET);
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
