/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:09:03 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/18 18:01:33 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_heredoc_2(t_token *token, t_env *env);
static void	ft_heredoc_3(t_token *heredoc, t_env *env, int pipefd[2]);
static int	ft_heredoc_4(t_token *token, int fd);
static int	ft_add_line(t_token **heredoc, char *line);

int	ft_heredoc(t_token *token, t_env *env)
{
	int	error;

	error = 0;
	signal(SIGINT, ft_ctrl_c_heredoc);
	while (token)
	{
		if (token->type == HERE_DOC_EX || token->type == HERE_DOC_NO)
			error = ft_heredoc_2(token, env);
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
	int		error;

	if (pipe(pipefd) == -1)
		return (PIPE_FAILED);
	pid = fork();
	if (pid == -1)
		return ((void)close(pipefd[STDIN_FILENO]), \
		(void)close(pipefd[STDIN_FILENO]), FORK_FAILED);
	if (!pid)
		ft_heredoc_3(heredoc, env, pipefd);
	close(pipefd[STDOUT_FILENO]);
	waitpid(pid, &error, 0);
	if (!WEXITSTATUS(error) && ft_heredoc_4(heredoc, pipefd[STDIN_FILENO]))
	{
		close(pipefd[STDIN_FILENO]);
		return (MALLOC_FAILED);
	}
	close(pipefd[STDIN_FILENO]);
	return (WEXITSTATUS(error));
}

static void	ft_heredoc_3(t_token *heredoc, t_env *env, int pipefd[2])
{
	int		error;

	error = 0;
	signal(SIGINT, ft_ctrl_c_heredoc_fork);
	close(pipefd[STDIN_FILENO]);
	if (heredoc->type == HERE_DOC_EX)
		error = ft_heredoc_expands(heredoc, env, pipefd[STDOUT_FILENO]);
	else if (heredoc->type == HERE_DOC_NO)
		error = ft_heredoc_no_expans(heredoc, pipefd[STDOUT_FILENO]);
	close(pipefd[STDOUT_FILENO]);
	ft_token_clear(ft_get_ptr_token(NULL));
	ft_exit_minishell(ft_get_data(NULL), error);
}

static int	ft_heredoc_4(t_token *token, int fd)
{
	char	*line;
	t_token	*heredoc;

	heredoc = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_add_line(&heredoc, line))
			return (ft_token_clear(&heredoc), free(line), MALLOC_FAILED);
	}
	if (ft_fusion_line(heredoc))
		return (ft_token_clear(&heredoc), free(line), MALLOC_FAILED);
	ft_replace_heredoc_content(token, heredoc);
	free(heredoc);
	free(line);
	return (0);
}

static int	ft_add_line(t_token **heredoc, char *line)
{
	t_token	*new;
	char	*str;

	new = ft_token_new(line, HERE_DOC_NO);
	if (!new)
		return (MALLOC_FAILED);
	ft_token_add_back(heredoc, new);
	str = ft_strdup("\n");
	if (!str)
		return (MALLOC_FAILED);
	new = ft_token_new(str, HERE_DOC_NO);
	if (!new)
	{
		free(str);
		return (MALLOC_FAILED);
	}
	ft_token_add_back(heredoc, new);
	return (0);
}
