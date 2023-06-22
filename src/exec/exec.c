/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:39:05 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/22 14:14:32 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_isbuiltin(t_minishell *data);
static void	ft_pipe(t_minishell *data);
static void	ft_execve(t_minishell *data);
static void	child_process(t_minishell *data);

int	ft_exec(t_minishell *data)
{
	if (!data->lcmd->next && data->lcmd->cmd && ft_isbuiltin(data))
		return (g_error);
	data->pid = fork();
	if (data->pid == -1)
		ft_error(data, FORK_FAILED);
	if (!data->pid)
		ft_pipe(data);
	waitpid(data->pid, &g_error, 0);
	g_error = WEXITSTATUS(g_error);
	return (g_error);
}

static int	ft_isbuiltin(t_minishell *data)
{
	int	i;

	i = 0;
	if (!ft_strncmp(data->lcmd->cmd[0], "env", 4) && ++i && !ft_file(data))
		g_error = ft_env(data->env);
	else if (!ft_strncmp(data->lcmd->cmd[0], "pwd", 4) && ++i && !ft_file(data))
		g_error = ft_pwd();
	else if (!ft_strncmp(data->lcmd->cmd[0], "cd", 3) && ++i && !ft_file(data))
		g_error = ft_cd(&data->env, data->lcmd->cmd);
	else if (!ft_strncmp(data->lcmd->cmd[0], "echo", 5) && ++i && !ft_file(data))
		g_error = ft_echo(data->lcmd->cmd);
	else if (!ft_strncmp(data->lcmd->cmd[0], "export", 7) && ++i && !ft_file(data))
		g_error = ft_export(&data->env, data->lcmd->cmd);
	else if (!ft_strncmp(data->lcmd->cmd[0], "unset", 6) && ++i && !ft_file(data))
		g_error = ft_unset(&data->env, data->lcmd->cmd);
	else if (!ft_strncmp(data->lcmd->cmd[0], "exit", 5) && ++i && !ft_file(data))
		g_error = ft_exit(data);
	data->out = 1;
	return (i);
}

void	ft_pipe(t_minishell *data)
{
	int	error;

	if (ft_get_path(data))
		ft_error(data, MALLOC_FAILED);
	while (data->lcmd)
		ft_execve(data);
	waitpid(data->pid, &g_error, 0);
	while (waitpid(-1, &error, 0) != -1)
	{
		if (WEXITSTATUS(error) == MALLOC_FAILED)
			g_error = error;
	}
	if (!WIFSIGNALED(g_error))
		g_error = WEXITSTATUS(g_error);
	else if (WIFSIGNALED(g_error))
	{
		ft_putstr_fd("\n", 1);
		g_error = 128 + WTERMSIG(g_error);
	}
	ft_exit_minishell(data, g_error);
}

static void	ft_execve(t_minishell *data)
{
	t_lcmd	*tmp;

	if (pipe(data->pipefd) == -1)
	{
		while (waitpid(-1, NULL, 0) != -1)
			;
		ft_error(data, PIPE_FAILED);
	}
	data->pid = fork();
	if (data->pid == -1)
	{
		while (waitpid(-1, NULL, 0) != -1)
			;
		ft_error(data, FORK_FAILED);
	}
	if (!data->pid)
		child_process(data);
	tmp = data->lcmd;
	data->lcmd = data->lcmd->next;
	ft_lcmd_delone(tmp);
	ft_close(&data->pipefd[STDOUT_FILENO]);
	ft_dup(data->pipefd[STDIN_FILENO], STDIN_FILENO, data);
}

static void	child_process(t_minishell *data)
{
	char	*path_cmd;
	char	**env;

	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, ft_ctrl_c_exec);
	if (data->lcmd->cmd && ft_isbuiltin(data))
		ft_exit_minishell(data, g_error);
	ft_file(data);
	if (data->lcmd->cmd)
	{
		path_cmd = ft_check_cmd(data);
		env = ft_env_to_tab(data->env);
		execve(path_cmd, data->lcmd->cmd, env);
		ft_free_split(env);
		free(path_cmd);
	}
	ft_exit_minishell(data, g_error);
}
