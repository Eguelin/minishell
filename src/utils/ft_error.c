/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:53:34 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/20 09:15:16 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error(t_minishell *data, int error)
{
	if (error == 130)
		ft_putstr_fd("\n", 1);
	if (error == SYNTAX_ERROR)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token\n", 2);
		g_error = 2;
	}
	else if (error == MALLOC_FAILED || error == PIPE_FAILED \
	|| error == FORK_FAILED)
	{
		ft_putstr_fd("minishell: alloc failed !\n", 2);
		ft_exit_minishell(data, 1);
	}
	else if (!data->lcmd)
		return ;
}
