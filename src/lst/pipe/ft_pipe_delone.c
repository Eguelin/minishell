/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:38:12 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/23 14:55:06 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pipe_delone(t_pipe *pipe)
{
	if (!pipe)
		return ;
	ft_free_split(pipe->cmd);
	ft_file_clear(&pipe->in);
	ft_file_clear(&pipe->out);
	free(pipe);
}
