/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:31:31 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/15 16:11:17 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_minishell *data)
{
	int	returntype;

	if (data->lcmd->cmd[1])
		returntype = ft_atoi(data->lcmd->cmd[1]);
	else
		returntype = g_error;
	if (data->lcmd->cmd[2])
	{
		printf("cc\n");
		return ;
	}
	ft_exit_minishell(data, returntype);
}
//ne fait rien si plus que un code
//20 chiffre ou + error
