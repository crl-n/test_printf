/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:08:31 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/17 15:46:57 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	redirect_stdout(char *filename, int *saved_stdout, int *fd)
{
	if (!filename)
		return (-1);
	*saved_stdout = dup(STDOUT_FILENO);
	if (*saved_stdout < 0)
		return (-1);
	*fd = open(filename, O_RDWR | O_CREAT, 0777);
	if (*fd < 0)
		return (-1);
	dup2(*fd, STDOUT_FILENO);
	return (0);
}

void	restore_stdout(int	saved_stdout, int fd)
{
	close(STDOUT_FILENO);
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);
	close(fd);
}
