/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fusion_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 20:03:10 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/01 20:03:33 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_join_token(t_token **tmp, char **new_content, int *type);
size_t	ft_size_join_token(t_token *tmp);

int	ft_fusion_line(t_token **token)
{
	t_token	*new_token;
	t_token	*new;
	t_token	*tmp;
	char	*new_content;
	int		type;

	new_token = NULL;
	tmp = *token;
	while (tmp)
	{
		if (ft_join_token(&tmp, &new_content, &type))
			return (1);
		new = ft_token_new(new_content, type);
		if (!new)
			return (ft_token_clear(&new_token), 1);
		ft_token_add_back(&new_token, new);
	}
	ft_token_clear(token);
	*token = new_token;
	return (0);
}

int	ft_join_token(t_token **tmp, char **new_content, int *type)
{
	size_t	size;

	*type = 0;
	if (*tmp && (*tmp)->type < 0)
	{
		*new_content = NULL;
		*tmp = (*tmp)->next;
		return (0);
	}
	size = ft_size_join_token(*tmp);
	*new_content = ft_calloc(sizeof(char), size + 1);
	if (!*new_content)
		return (1);
	while (*tmp && (*tmp)->type > 0)
	{
		ft_strlcat(*new_content, (*tmp)->content, size + 1);
		if (*type < (*tmp)->type)
			*type = (*tmp)->type;
		*tmp = (*tmp)->next;
	}
	while (*tmp && !(*tmp)->type)
		*tmp = (*tmp)->next;
	return (0);
}

size_t	ft_size_join_token(t_token *tmp)
{
	size_t	size;

	size = 0;
	while (tmp && tmp->type > 0)
	{
		size += ft_strlen(tmp->content);
		tmp = tmp->next;
	}
	return (size);
}
