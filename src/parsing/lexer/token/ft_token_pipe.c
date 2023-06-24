/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:26:09 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/23 17:18:50 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_token_pipe(t_data_token *data)
{
	t_token	*new;

	if (!*data->token)
		return (SYNTAX_ERROR);
	data->type = PIPE;
	new = ft_token_new(NULL, data->type);
	if (!new)
		return (MALLOC_FAILED);
	ft_token_add_back(data->token, new);
	(data->end)++;
	data->type = ISOLATOR;
	while (data->line[data->end] && ft_strchr(" \t\n\v\f\r", data->line[data->end]))
		(data->end)++;
	if (!data->line[data->end])
		return (SYNTAX_ERROR);
	else if (data->line[data->end] == '|')
		return (SYNTAX_ERROR);
	data->start = data->end;
	return (0);
}
