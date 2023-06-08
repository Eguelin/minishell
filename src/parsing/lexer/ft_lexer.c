/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:34:36 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/08 19:51:35 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_fusion_line(t_token *token);
static int		ft_join_token(t_token *token);
static size_t	ft_size_join_token(t_token *token);
int				ft_syntax_error(int i);

int	ft_lexer(t_token **token, t_env *env, char *line)
{
	t_data_token	data;
	int				error;

	data.token = token;
	data.line = line;
	data.end = 0;
	while (line[data.end] == ' ')
		(data.end)++;
	data.start = data.end;
	data.type = 0;
	while (line[data.end])
	{
		error = ft_get_token(&data, env);
		if (error)
			return (ft_syntax_error(error));
	}
	ft_fusion_line(*token);
	return (0);
}

static int	ft_fusion_line(t_token *token)
{
	while (token && token->next)
	{
		if (token->next->type > 0 && ft_join_token(token))
			return (1);
		if (token->next && !token->next->type)
			ft_token_delone(token->next);
		if (token->next && token->next->type < 0)
			token = token->next;
		token = token->next;
	}
	return (0);
}

static int	ft_join_token(t_token *token)
{
	size_t	size;
	char	*new_content;

	size = ft_size_join_token(token);
	new_content = malloc(sizeof(char) * size + 1);
	if (!new_content)
		return (1);
	ft_strlcpy(new_content, token->content, size + 1);
	while (token->next && token->next->type > 0)
	{
		ft_strlcat(new_content, token->next->content, size + 1);
		if (token->type < token->next->type)
			token->type = token->next->type;
		ft_token_delone(token->next);
	}
	free(token->content);
	token->content = new_content;
	return (0);
}

static size_t	ft_size_join_token(t_token *token)
{
	size_t	size;

	size = 0;
	while (token && token->type > 0)
	{
		size += ft_strlen(token->content);
		token = token->next;
	}
	return (size);
}

int	ft_syntax_error(int error)
{
	if (error == '\n')
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
		return (2);
	}
	else if (error > 1)
	{
		printf("minishell: syntax error near unexpected token `%c'\n", error);
		return (2);
	}
	return (error);
}
