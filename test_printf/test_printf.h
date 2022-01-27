/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:54:24 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/27 12:41:08 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_PRINTF_H
# define TEST_PRINTF_H

# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYAN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"

int		compare_output(void);
int		redirect_stdout(char *filename, int *saved_stdout, int *fd);
void	restore_stdout(int	saved_stdout, int fd);

void	general_tests(void);
void	c_tests(void);
void	s_tests(void);
void	p_tests(void);

#endif
