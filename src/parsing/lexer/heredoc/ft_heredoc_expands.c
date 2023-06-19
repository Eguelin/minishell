/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_expands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 19:00:49 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/19 18:34:51 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_putstr_line(char *line, t_env *env, int fd);
static int	ft_putstr_ex(char *line, t_env *env, size_t	*start, int fd);

int	ft_heredoc_expands(t_token *token, t_env *env, int fd)
{
	char	*line;

	token->type = fd + HERE_DOC_NO;
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (!ft_strncmp(line, token->content, ft_strlen(token->content) + 1))
			break ;
		if (ft_putstr_line(line, env, fd))
			return (free(line), MALLOC_FAILED);
		ft_putstr_fd("\n", fd);
		free(line);
	}
	if (!line)
		ft_putstr_fd("minishell: warning: here-document "\
		"delimited by end-of-file\n", 2);
	free(line);
	return (0);
}

static int	ft_putstr_line(char *line, t_env *env, int fd)
{
	size_t	index[2];

	index[0] = 0;
	index[1] = 0;
	while (line[index[1]])
	{
		while (line[index[1]] && line[index[1]] != '$')
			index[1]++;
		write(1, line + index[0], index[1] - index[0]);
		if (line[index[1]])
			index[0] = index[1]++;
		if (ft_putstr_ex(line, env, index, fd))
			return (MALLOC_FAILED);
	}
	return (0);
}

static int	ft_putstr_ex(char *line, t_env *env, size_t index[2], int fd)
{
	char	*name;

	name = NULL;
	if (ft_isdigit(line[index[1]]))
	{
		index[0] = ++(index[1]);
		return (0);
	}
	else
		while (ft_isalnum(line[index[1]]) || line[index[1]] == '_')
			(index[1])++;
	if (index[1] - index[0] > 1)
	{
		(index[0])++;
		name = ft_substr(line, index[0], index[1] - index[0]);
		if (!name)
			return (MALLOC_FAILED);
		env = ft_get_env(env, name);
		if (env && env->content)
			ft_putstr_fd(env->content, 1);
	}
	else
		ft_putstr_fd("$", fd);
	index[0] = index[1];
	return (free(name), 0);
}
