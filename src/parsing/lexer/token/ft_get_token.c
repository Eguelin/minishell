/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:26:09 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/23 17:18:43 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_token(t_data_token *data, t_env *env)
{
	int	error;

	if (ft_strchr("<>", data->line[data->end]))
		error = ft_token_chevron(data);
	else if (ft_strchr("\"'", data->line[data->end]))
		error = ft_token_quote(data, env);
	else if (data->line[data->end] == '|')
		error = ft_token_pipe(data);
	else if (ft_strchr(" \t\n\v\f\r", data->line[data->end]))
		error = ft_token_space(data);
	else if (data->line[data->end] == '$')
		error = ft_token_dollar(data, env, 0);
	else
		error = ft_token_word(data);
	return (error);
}
