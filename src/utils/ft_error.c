/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:53:34 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/21 12:24:04 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error(t_minishell *data, int error)
{
	if (error == SYNTAX_ERROR)
	{
		ft_printf_error("%s: syntax error near unexpected token\n", data->name);
		g_error = 2;
	}
	else if (error == MALLOC_FAILED || error == PIPE_FAILED \
	|| error == FORK_FAILED)
	{
		ft_printf_error("%s: alloc failed !\n", data->name);
		ft_exit_minishell(data, 1);
	}
	else if (!data->lcmd)
		return ;
}
