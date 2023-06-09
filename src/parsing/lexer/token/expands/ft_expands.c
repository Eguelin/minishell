/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expands.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:10:37 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/09 14:42:20 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_expands(t_data_token *data, t_env *env, char *name, int i)
{
	if (name[0] == '?')
	{
		if (ft_expands_global(data))
			return (1);
		return (0);
	}
	env = ft_env_chr(env, name);
	if (!env && data->type >= IN)
	{
		(data->type)--;
		data->start = data->end;
		if (ft_add_token(data))
			return (1);
		(data->type)++;
	}
	else if (!env || !env->content || !env->content[0])
	{
		data->start = data->end;
		data->type = ISOLATOR;
	}
	else if (i && ft_expands_quote(data, env->content))
		return (1);
	else if (!i && ft_expands_classic(data, env->content))
		return (1);
	return (0);
}
