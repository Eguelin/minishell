/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:26:09 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/30 11:53:48 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_token_pipe(t_data_token *data)
{
	if (!(data->token))
		return ('|');
	(data->end)++;
	data->type = PIPE;
	if (ft_add_token(data))
		return (130);
	data->type = ISOLATOR;
	while (data->line[data->end] == ' ')
		(data->end)++;
	if (!data->line[data->end])
		return ('|');
	else if (data->line[data->end] == '|')
		return ('|');
	data->start = data->end;
	return (0);
}