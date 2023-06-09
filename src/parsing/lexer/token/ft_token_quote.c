/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:26:09 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/29 18:03:01 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_dlr_quote(t_data_token *data, t_env *env);

int	ft_token_quote(t_data_token *data, t_env *env)
{
	char	c;

	if (!data->type)
		data->type = WORD;
	else if (data->type == HERE_DOC_EX)
		data->type = HERE_DOC_NO;
	c = data->line[(data->end)++];
	data->start = data->end;
	while (data->line[data->end] && data->line[data->end] != c)
	{
		if (data->type != HERE_DOC_NO && c == '"' \
		&& data->line[data->end] == '$' && ft_dlr_quote(data, env))
			return (MALLOC_FAILED);
		else if ((c == '\'' && data->line[data->end] != c) || \
		(data->line[data->end] != '$' && data->line[data->end] != c))
			(data->end)++;
	}
	if (!data->line[data->end])
		return (SYNTAX_ERROR);
	if (ft_add_token(data))
		return (MALLOC_FAILED);
	data->end++;
	data->start = data->end;
	return (0);
}

static int	ft_dlr_quote(t_data_token *data, t_env *env)
{
	if (ft_add_token(data))
		return (MALLOC_FAILED);
	data->start = data->end;
	if (ft_token_dollar(data, env, 1))
		return (MALLOC_FAILED);
	if (!data->type)
		data->type = 1;
	return (0);
}
