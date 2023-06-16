/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:39:05 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/16 17:42:17 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isbuiltin(t_minishell *data)
{
	int	i;

	i = 0;
	if (!ft_strncmp(data->lcmd->cmd[0], "env", 4) && ++i)
		ft_env(data->env);
	else if (!ft_strncmp(data->lcmd->cmd[0], "pwd", 4) && ++i)
		ft_pwd();
	else if (!ft_strncmp(data->lcmd->cmd[0], "cd", 3) && ++i)
		ft_cd(&data->env, data->lcmd->cmd);
	else if (!ft_strncmp(data->lcmd->cmd[0], "echo", 5) && ++i)
		ft_echo(data->lcmd->cmd);
	else if (!ft_strncmp(data->lcmd->cmd[0], "export", 7) && ++i)
		ft_export(&data->env, data->lcmd->cmd);
	else if (!ft_strncmp(data->lcmd->cmd[0], "unset", 6) && ++i)
		ft_unset(&data->env, data->lcmd->cmd);
	else if (!ft_strncmp(data->lcmd->cmd[0], "exit", 5) && ++i)
		ft_exit(data);
	return (i);
}

// void	ft_execve(t_minishell *data)
// {
// 	pid_t	pid;

// 	pid = fork();
// 	if (pid == -1)
// 		return ;
// 	else
// 	{
// 		//ft_in
// 		//ft_out
// 		if (ft_isbuiltin(data))
// 			exit(g_error);
// 		// else
// 		// 	execve()
// 	}
// }

int	ft_exec(t_minishell *data)
{
	t_lcmd	*tmp;

	if (!data->lcmd->next && ft_isbuiltin(data))
		return (g_error);
	while (data->lcmd)
	{
		//ft_execve(data);
		tmp = data->lcmd;
		data->lcmd = data->lcmd->next;
		ft_lcmd_delone(tmp);
	}
	return (0);
}
