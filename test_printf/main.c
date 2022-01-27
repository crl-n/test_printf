/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:48:16 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/27 11:23:30 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_printf.h"
#include "ft_printf.h"
#include <stdio.h>
#include <string.h>

static void	banner(void)
{
	printf(MAG"********************************************************************************\n"RESET);
	printf("%45s\n", "test_printf");
	printf(MAG"********************************************************************************\n"RESET);
	fflush(NULL);
}

int	main(void)
{
	banner();
	c_tests();
	s_tests();
	p_tests();
	return (0);
}
