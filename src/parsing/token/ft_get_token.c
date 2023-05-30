/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:26:09 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/30 15:13:48 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_token(t_data_token *data, t_env *env)
{
	int	i;

	if (ft_strchr("<>", data->line[data->end]))
		i = ft_token_chevron(data);
	else if (ft_strchr("\"'", data->line[data->end]))
		i = ft_token_quote(data, env);
	else if (data->line[data->end] == '|')
		i = ft_token_pipe(data);
	else if (data->line[data->end] == ' ')
		i = ft_token_space(data);
	else if (data->line[data->end] == '$')
		i = ft_token_dollar(data, env, 0);
	else
		i = ft_token_word(data);
	return (i);
}
