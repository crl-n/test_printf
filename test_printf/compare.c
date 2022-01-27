/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:07:25 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/27 22:51:58 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_printf.h"
#include <stdio.h>
#include <string.h>

int	compare_output(void)
{
	FILE *stream = fopen("output", "r");
	size_t	linecapp_ft = 0;
	size_t	linecapp_orig = 0;
	ssize_t	linelen_ft = 0;
	ssize_t	linelen_orig = 0;
	char	*line_ft = NULL;
	char	*line_orig = NULL;
	int		ret = 1;

	if (!stream)
		return (1);
	while (1)
	{
		linelen_ft = getline(&line_ft, &linecapp_ft, stream);
		linelen_orig = getline(&line_orig, &linecapp_orig, stream);
		if (linelen_orig <= 0 || linelen_ft <= 0)
			break ;
		if (strcmp(line_ft, line_orig))
		{
			printf("%s !=\n%s\n", line_ft, line_orig);
			ret = 0;
		}
	}
	return (ret);
}
