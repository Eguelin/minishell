/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:38:37 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/29 11:45:02 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_dup(int fd, int fd2, t_minishell *data)
{
	if (fd == -1)
		return ;
	if (data->pid && data->pipefd[STDIN_FILENO] != fd)
		;
	else if (dup2(fd, fd2) == -1)
	{
		close(fd);
		if (fd == data->pipefd[0])
			data->pipefd[0] = -1;
		else if (fd == data->pipefd[1])
			data->pipefd[1] = -1;
		while (waitpid(-1, NULL, 0) != -1)
			;
		ft_exit_minishell(data, OPEN_FAILED);
	}
	close(fd);
	if (fd == data->pipefd[0])
		data->pipefd[0] = -1;
	else if (fd == data->pipefd[1])
		data->pipefd[1] = -1;
}
