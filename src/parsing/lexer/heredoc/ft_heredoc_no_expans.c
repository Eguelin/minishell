/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_no_expans.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 19:00:46 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/17 19:04:03 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_add_line(t_token **heredoc, char *line);

int	ft_heredoc_no_expans(t_token *token)
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
		if (ft_add_line(&heredoc, line))
			return (ft_token_clear(&heredoc), free(line), MALLOC_FAILED);
	}
	if (!line)
		return (ft_putstr_fd("minishell: warning: here-document at "\
		"line 1 delimited by end-of-file\n", 2), 0);
	if (ft_fusion_line(heredoc))
		return (ft_token_clear(&heredoc), free(line), MALLOC_FAILED);
	free(token->content);
	token->content = heredoc->content;
	free(heredoc);
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
