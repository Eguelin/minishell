/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fusion_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:34:36 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/17 17:59:34 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_join_token(t_token *token);
static size_t	ft_size_join_token(t_token *token);

int	ft_fusion_line(t_token *token)
{
	while (token && token->next)
	{
		if (token->next->type > 0 && ft_join_token(token))
			return (MALLOC_FAILED);
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
		return (MALLOC_FAILED);
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
