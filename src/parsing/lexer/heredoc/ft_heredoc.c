/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:09:03 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/29 17:34:57 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_heredoc_fork(t_token *token, t_env *env);
static void	ft_heredoc_child(t_token *heredoc, t_env *env, int pipefd[2]);
static int	ft_heredoc_export(t_token *heredoc, int fd);

int	ft_heredoc(t_token *token, t_env *env)
{
	int	error;

	error = 0;
	signal(SIGINT, SIG_IGN);
	while (token)
	{
		if (token->type == HERE_DOC_EX || token->type == HERE_DOC_NO)
			error = ft_heredoc_fork(token, env);
		if (error == 130)
			ft_putstr_fd("\n", 1);
		if (error)
			return (error);
		token = token->next;
	}
	return (0);
}

static int	ft_heredoc_fork(t_token *heredoc, t_env *env)
{
	pid_t	pid;
	int		pipefd[2];
	int		error;

	error = 0;
	if (pipe(pipefd) == -1)
		return (PIPE_FAILED);
	pid = fork();
	if (pid == -1)
	{
		close(pipefd[STDOUT_FILENO]);
		close(pipefd[STDIN_FILENO]);
		return (FORK_FAILED);
	}
	if (!pid)
		ft_heredoc_child(heredoc, env, pipefd);
	close(pipefd[STDOUT_FILENO]);
	error = ft_heredoc_export(heredoc, pipefd[STDIN_FILENO]);
	waitpid(pid, &g_error, 0);
	close(pipefd[STDIN_FILENO]);
	if (error)
		return (error);
	g_error = WEXITSTATUS(g_error);
	return (g_error);
}

static void	ft_heredoc_child(t_token *heredoc, t_env *env, int pipefd[2])
{
	int		error;

	error = 0;
	signal(SIGINT, ft_ctrl_c_heredoc);
	close(pipefd[STDIN_FILENO]);
	if (heredoc->type == HERE_DOC_EX)
		error = ft_heredoc_expands(heredoc, env, pipefd[STDOUT_FILENO]);
	else if (heredoc->type == HERE_DOC_NO)
		error = ft_heredoc_no_expans(heredoc, pipefd[STDOUT_FILENO]);
	close(pipefd[STDOUT_FILENO]);
	ft_token_clear(ft_get_ptr_token(NULL));
	ft_exit_minishell(ft_get_data(NULL), error);
}

static int	ft_heredoc_export(t_token *heredoc, int fd)
{
	char	*line;
	int		fd_tmp;
	int		error;

	error = ft_open_heredoc(heredoc, &fd_tmp);
	if (error)
		return (error);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_printf_fd(fd_tmp, "%s", line);
		free(line);
	}
	close(fd_tmp);
	return (0);
}
