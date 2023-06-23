/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:09:03 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/23 16:08:51 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_heredoc_2(t_token *token, t_env *env);
static void	ft_heredoc_3(t_token *heredoc, t_env *env, int pipefd[2]);

int	ft_heredoc(t_token *token, t_env *env)
{
	int	error;

	error = 0;
	signal(SIGINT, SIG_IGN);
	while (token)
	{
		if (token->type == HERE_DOC_EX || token->type == HERE_DOC_NO)
			error = ft_heredoc_2(token, env);
		if (error == 130)
			ft_putstr_fd("\n", 1);
		if (error)
			return (error);
		token = token->next;
	}
	return (0);
}

static int	ft_heredoc_2(t_token *heredoc, t_env *env)
{
	pid_t	pid;
	int		pipefd[2];

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
		ft_heredoc_3(heredoc, env, pipefd);
	close(pipefd[STDOUT_FILENO]);
	waitpid(pid, &g_error, 0);
	free(heredoc->content);
	heredoc->content = NULL;
	heredoc->type = pipefd[STDIN_FILENO] + HERE_DOC_NO;
	g_error = WEXITSTATUS(g_error);
	return (g_error);
}

static void	ft_heredoc_3(t_token *heredoc, t_env *env, int pipefd[2])
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
