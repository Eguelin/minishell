/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:01:41 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/21 15:47:42 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_file(t_minishell *data)
{
	int	in;
	int	out;

	in = STDIN_FILENO;
	out = STDOUT_FILENO;
	ft_close(&data->pipefd[0]);
	if (data->lcmd->next)
		ft_dup(data->pipefd[1], STDOUT_FILENO, data);
	else
		ft_close(&data->pipefd[1]);
}
