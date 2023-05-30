/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:10:37 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/30 16:29:40 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_expend(t_data_token *data, t_env *env, char *name, int i)
{
	t_token	*new;

	env = ft_env_chr(env, name);
	if (!env)
	{
		new = ft_token_new(NULL, data->type);
		if (!new)
			return (1);
		ft_token_add_back(data->token, new);
	}
	else if (i && ft_expend_quote(data, env->content))
		return (1);
	else if (!i && ft_expend_classic(data, env->content))
		return (1);
	return (0);
}
