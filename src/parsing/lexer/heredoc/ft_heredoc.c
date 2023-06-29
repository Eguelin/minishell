/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:09:03 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/29 12:21:29 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_heredoc_2(t_token *token, t_env *env, int i);
static void	ft_heredoc_3(t_token *heredoc, t_env *env, int pipefd[2]);
static int	ft_heredoc_4(t_token *heredoc, int fd, int i);
static int	ft_open_here(t_token *heredoc, int i, int *fd_tmp);

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
			error = ft_heredoc_2(token, env, i++);
		if (error == 130)
			ft_putstr_fd("\n", 1);
		if (error)
			return (error);
		token = token->next;
	}
	return (0);
}

static int	ft_heredoc_2(t_token *heredoc, t_env *env, int i)
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
		ft_heredoc_3(heredoc, env, pipefd);
	close(pipefd[STDOUT_FILENO]);
	error = ft_heredoc_4(heredoc, pipefd[STDIN_FILENO], i);
	waitpid(pid, &g_error, 0);
	close(pipefd[STDIN_FILENO]);
	if (error)
		return (error);
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

static int	ft_heredoc_4(t_token *heredoc, int fd, int i)
{
	char	*line;
	int		fd_tmp;
	int		error;

	error = ft_open_here(heredoc, i, &fd_tmp);
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

static int	ft_open_here(t_token *heredoc, int i, int *fd_tmp)
{
	char	*name;
	char	*nbr;

	nbr = ft_itoa(i);
	if (!nbr)
		return (MALLOC_FAILED);
	name = ft_strjoin("/var/tmp/herdoc", nbr);
	if (!name)
		return (free(nbr), MALLOC_FAILED);
	free(heredoc->content);
	heredoc->content = name;
	free(nbr);
	*fd_tmp = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (*fd_tmp == -1)
		return (ft_printf_error("%s: Error opening temporary file\n", \
		ft_get_data(NULL)->name), free(name), OPEN_FAILED);
	return (0);
}
