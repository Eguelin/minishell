/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:09:03 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/29 11:40:01 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_heredoc_2(t_token *token, t_env *env);
static void	ft_heredoc_3(t_token *heredoc, t_env *env, int pipefd[2]);
static int	ft_heredoc_4(t_token *heredoc, int fd);
static int	ft_add_line(t_token **heredoc, char *line);

int	ft_heredoc(t_token *token, t_env *env)
{
	int	error;
	int	i;

	error = 0;
	i = 0;
	signal(SIGINT, SIG_IGN);
	while (token)
	{
		if (token->type == HERE_DOC_EX || token->type == HERE_DOC_NO)
		{
			error = ft_heredoc_2(token, env);
			token->type = HERE_DOC_NO + i++;
		}
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
	ft_heredoc_4(heredoc, pipefd[STDIN_FILENO]);
	waitpid(pid, &g_error, 0);
	close(pipefd[STDIN_FILENO]);
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

static int	ft_heredoc_4(t_token *heredoc, int fd)
{
	char	*line;
	t_token	*tmp;

	tmp = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_add_line(&tmp, line))
			return (ft_token_clear(&tmp), free(line), MALLOC_FAILED);
	}
	if (ft_add_line(&tmp, NULL))
		return (ft_token_clear(&tmp), MALLOC_FAILED);
	if (ft_fusion_line(tmp))
		return (ft_token_clear(&tmp), free(line), MALLOC_FAILED);
	free(heredoc->content);
	heredoc->content = tmp->content;
	free(tmp);
	free(line);
	return (0);
}

static int	ft_add_line(t_token **heredoc, char *line)
{
	t_token	*new;
	char	*void_line;

	void_line = NULL;
	if (!line)
	{
		void_line = malloc(sizeof(char));
		if (!void_line)
			return (MALLOC_FAILED);
		void_line[0] = '\0';
		new = ft_token_new(void_line, 1);
	}
	else
		new = ft_token_new(line, 1);
	if (!new)
		return (free(void_line), MALLOC_FAILED);
	ft_token_add_back(heredoc, new);
	return (0);
}
