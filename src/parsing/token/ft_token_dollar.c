/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_dollar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:26:09 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/30 17:10:18 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_var_nane(t_data_token *data, t_env *env, int i);

int	ft_token_dollar(t_data_token *data, t_env *env, int i)
{
	t_token	*new;

	(data->end)++;
	if (data->type >= HERE_DOC_EX && ft_add_token(data))
		return (130);
	else if (ft_isdigit(data->line[data->end]))
	{
		new = ft_token_new(NULL, data->type);
		if (!new)
			return (1);
		ft_token_add_back(data->token, new);
		(data->end)++;
	}
	else if (ft_var_nane(data, env, i))
		return (130);
	data->start = data->end;
	return (0);
}

static int	ft_var_nane(t_data_token *data, t_env *env, int i)
{
	char	*name;

	while (ft_isalnum(data->line[data->end]) || data->line[data->end] == '_')
		(data->end)++;
	if (data->end - data->start > 1)
	{
		name = ft_substr(data->line, data->start, data->end - data->start);
		if (!name)
			return (130);
		if (ft_expend(data, env, name + 1, i))
		{
			free(name);
			return (130);
		}
		free(name);
	}
	else if (ft_add_token(data))
		return (130);
	return (0);
}
