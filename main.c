/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:48:16 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/17 18:12:34 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_printf.h"
#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	compare_output(void)
{
	FILE *stream = fopen("output", "r");
	size_t	linecapp_ft = 0;
	size_t	linecapp_orig = 0;
	ssize_t	linelen_ft = 0;
	ssize_t	linelen_orig = 0;
	char	*line_ft = NULL;
	char	*line_orig = NULL;
	if (!stream)
		return (1);
	while (1)
	{
		linelen_ft = getline(&line_ft, &linecapp_ft, stream);
		linelen_orig = getline(&line_orig, &linecapp_orig, stream);
		if (linelen_orig <= 0 || linelen_ft <= 0)
			break ;
		if (strcmp(line_ft, line_orig))
			printf("%s != %s\n", line_ft, line_orig);
	}
	return (0);
}

int	main(void)
{
	int	fd;
	int	saved_stdout;
	char	*s1 = strdup("hello world");

	if (redirect_stdout("output", &saved_stdout, &fd) < 0)
		return (1);
	ft_printf("%s\n", s1);
	printf("%s\n", s1);
	fflush(NULL);
	ft_printf("%p\n", s1);
	printf("%p\n", s1);
	fflush(NULL);
	ft_printf("%s\n", "buu");
	printf("%s\n","baa");
	fflush(NULL);
	restore_stdout(saved_stdout, fd);
	free(s1);
	if (compare_output())
		return (1);
	return (0);
}
