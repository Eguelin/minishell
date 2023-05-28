/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:26:09 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/28 19:07:34 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_dlr_quote(t_data_token *data);

int	ft_token_quote(t_data_token *data)
{
	char	c;

	c = data->line[(data->end)++];
	if (ft_add_token(data))
		return (130);
	data->start = data->end;
	while (data->line[data->end] && data->line[data->end] != c)
	{
		if (c == '"' && data->line[data->end] == '$')
		{
			if (ft_dlr_quote(data))
				return (131);
		}
		else if (data->line[data->end] != c)
			(data->end)++;
	}
	if (!data->line[data->end])
		return (131);
	if (ft_add_token(data))
		return (130);
	data->start = (data->end)++;
	if (ft_add_token(data))
		return (130);
	data->start = data->end;
	return (0);
}

static int	ft_dlr_quote(t_data_token *data)
{
	if (ft_add_token(data))
		return (1);
	data->start = data->end;
	if (ft_token_dollar(data))
		return (1);
	return (0);
}
