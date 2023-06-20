/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:39:05 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/20 16:00:24 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isbuiltin(t_minishell *data)
{
	int	i;

	i = 0;
	if (!ft_strncmp(data->lcmd->cmd[0], "env", 4) && ++i)
		g_error = ft_env(data->env);
	else if (!ft_strncmp(data->lcmd->cmd[0], "pwd", 4) && ++i)
		g_error = ft_pwd();
	else if (!ft_strncmp(data->lcmd->cmd[0], "cd", 3) && ++i)
		g_error = ft_cd(&data->env, data->lcmd->cmd);
	else if (!ft_strncmp(data->lcmd->cmd[0], "echo", 5) && ++i)
		g_error = ft_echo(data->lcmd->cmd);
	else if (!ft_strncmp(data->lcmd->cmd[0], "export", 7) && ++i)
		g_error = ft_export(&data->env, data->lcmd->cmd);
	else if (!ft_strncmp(data->lcmd->cmd[0], "unset", 6) && ++i)
		g_error = ft_unset(&data->env, data->lcmd->cmd);
	else if (!ft_strncmp(data->lcmd->cmd[0], "exit", 5) && ++i)
		g_error = ft_exit(data);
	return (i);
}

static int	child_process(t_minishell *data)
{
	char	*path_cmd;
	char	**env;
	if (ft_isbuiltin(data))
		ft_exit_minishell(data, g_error);
	env = ft_env_to_tab(data->env);
	path_cmd = ft_check_cmd(data);
	execve(path_cmd, data->lcmd->cmd, env);
	ft_free_split(env);
	free(path_cmd);
	ft_exit_minishell(data, g_error);
	return (0);
}

static int	ft_execve(t_minishell *data)
{
	t_lcmd	*tmp;

	data->pid = fork();
	if (data->pid == -1)
	{
		while (waitpid(-1, NULL, 0) != -1)
			;
		return (FORK_FAILED);
	}
	if (!data->pid)
		child_process(data);
	tmp = data->lcmd;
	data->lcmd = data->lcmd->next;
	ft_lcmd_delone(tmp);
	return (0);
}

int	ft_exec(t_minishell *data)
{
	if (!data->lcmd->next && ft_isbuiltin(data))
		return (g_error);
	if (ft_get_path(data))
		return (MALLOC_FAILED);
	while (data->lcmd)
		if (ft_execve(data))
			return (FORK_FAILED);
	waitpid(data->pid, NULL, 0);
	return (0);
}
