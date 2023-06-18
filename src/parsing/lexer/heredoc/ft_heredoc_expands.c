/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_expands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 19:00:49 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/18 16:38:48 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_add_line_ex(t_token **heredoc, char *line, t_env *env);
static int	ft_token_line_part(t_data_token *data);
static int	ft_new_line(t_token **heredoc);

int	ft_heredoc_expands(t_token *token, t_env *env, int fd)
{
	char	*line;
	t_token	*heredoc;

	heredoc = NULL;
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (!ft_strncmp(line, token->content, ft_strlen(token->content) + 1))
			break ;
		if (ft_add_line_ex(&heredoc, line, env))
			return (ft_token_clear(&heredoc), free(line), MALLOC_FAILED);
		free(line);
	}
	if (!line)
		ft_putstr_fd("minishell: warning: here-document "\
		"delimited by end-of-file\n", 2);
	if (ft_fusion_line(heredoc))
		return (ft_token_clear(&heredoc), free(line), MALLOC_FAILED);
	if (heredoc)
		ft_putstr_fd(heredoc->content, fd);
	ft_token_delone(heredoc);
	free(line);
	return (0);
}

static int	ft_add_line_ex(t_token **heredoc, char *line, t_env *env)
{
	t_data_token	data;
	int				error;

	data.token = heredoc;
	data.line = line;
	data.end = 0;
	data.start = 0;
	data.type = 1;
	while (line[data.end])
	{
		if (data.line[data.end] == '$')
			error = ft_token_dollar(&data, env, 1);
		else
			error = ft_token_line_part(&data);
		if (error)
			return (MALLOC_FAILED);
	}
	if (ft_new_line(heredoc))
		return (MALLOC_FAILED);
	return (0);
}

static int	ft_token_line_part(t_data_token *data)
{
	if (!data->type)
		data->type = 1;
	while (data->line[data->end] && data->line[data->end] != '$')
		(data->end)++;
	if (ft_add_token(data))
		return (MALLOC_FAILED);
	data->start = data->end;
	return (0);
}

static int	ft_new_line(t_token **heredoc)
{
	t_token	*new;
	char	*str;

	str = ft_strdup("\n");
	if (!str)
		return (MALLOC_FAILED);
	new = ft_token_new(str, WORD);
	if (!new)
	{
		free(str);
		return (MALLOC_FAILED);
	}
	ft_token_add_back(heredoc, new);
	return (0);
}
