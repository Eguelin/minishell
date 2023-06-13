/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:39:05 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/13 13:09:39 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isbuiltin(t_minishell *data)
{
	if (!ft_strncmp(data->pipe->cmd[0], "env", 4))
		ft_env(data->env);
	if (!ft_strncmp(data->pipe->cmd[0], "pwd", 4))
		ft_pwd();
	if (!ft_strncmp(data->pipe->cmd[0], "cd", 3))
		ft_cd(&data->env, data->pipe->cmd);
	if (!ft_strncmp(data->pipe->cmd[0], "echo", 4))
		ft_echo(data->pipe->cmd);
	if (!ft_strncmp(data->pipe->cmd[0], "export", 4))
		ft_export(&data->env, data->pipe->cmd);
	if (!ft_strncmp(data->pipe->cmd[0], "unset", 4))
		ft_unset(&data->env, data->pipe->cmd);
	return (0);
}

int	ft_exec(t_minishell *data)
{
	int	i;

	while (data->pipe)
	{
		i = ft_isbuiltin(data);
		if (i != 0)
			return (i);
		data->pipe = data->pipe->next;
	}
	return (0);
}
