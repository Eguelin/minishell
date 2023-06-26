/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_dollar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:26:09 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/26 18:15:09 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_var_nane(t_data_token *data, t_env *env, int i);

int	ft_token_dollar(t_data_token *data, t_env *env, int i)
{
	if (!data->type)
		data->type = 1;
	(data->end)++;
	if (data->type < IN && ft_isdigit(data->line[data->end]))
	{
		(data->end)++;
		data->type = ISOLATOR;
	}
	else if (data->type < HERE_DOC_EX && ft_var_nane(data, env, i))
		return (MALLOC_FAILED);
	else if (data->type >= HERE_DOC_EX && ft_add_token(data))
		return (MALLOC_FAILED);
	data->start = data->end;
	while (data->line[data->end] && \
	ft_strchr(" \t\n\v\f\r", data->line[data->end]))
		(data->end)++;
	if (data->line[data->end] == '|')
	{
		data->start = ++data->end;
		if (!data->line[data->end])
			return (SYNTAX_ERROR);
	}
	else
		data->end = data->start;
	return (0);
}

static int	ft_var_nane(t_data_token *data, t_env *env, int i)
{
	char	*name;

	if (!i && (data->line[data->end] == '\"' || data->line[data->end] == '\''))
		data->start++;
	else if (ft_isdigit(data->line[data->end]) || data->line[data->end] == '?')
		(data->end)++;
	else
		while (ft_isalnum(data->line[data->end]) \
		|| data->line[data->end] == '_')
			(data->end)++;
	if (data->end - data->start > 1)
	{
		name = ft_substr(data->line, data->start, data->end - data->start);
		if (!name)
			return (MALLOC_FAILED);
		if (ft_expands(data, env, name + 1, i))
		{
			free(name);
			return (MALLOC_FAILED);
		}
		free(name);
	}
	else if (ft_add_token(data))
		return (MALLOC_FAILED);
	return (0);
}
