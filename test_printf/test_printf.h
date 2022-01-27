/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:54:24 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/17 15:21:20 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_PRINTF_H
# define TEST_PRINTF_H

int		redirect_stdout(char *filename, int *saved_stdout, int *fd);
void	restore_stdout(int	saved_stdout, int fd);

#endif
