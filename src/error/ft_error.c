/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:53:34 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/14 09:48:12 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error(t_minishell *data, int error)
{
	if (error == SYNTAX_ERROR)
	{
		printf("Syntax error !\n");
		g_error = 2;
	}
	else if (error == MALLOC_FAILED)
	{
		printf("Malloc failed !\n");
		ft_exit_minishell(data, 1);
	}
	else if (!data->lcmd)
		return ;
	else
		g_error = error;
}
