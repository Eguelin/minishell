/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_chevron.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:26:09 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/28 19:07:27 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_token_chevron(t_data_token *data)
{
	char	c;

	c = data->line[data->end];
	while (data->line[data->end] == c)
		(data->end)++;
	if (data->end - data->start > 2)
		return (data->line[data->end - 1]);
	if (ft_add_token(data))
		return (130);
	while (data->line[data->end] == ' ')
		(data->end)++;
	if (!data->line[data->end])
		return (131);
	else if (ft_strchr("<>|", data->line[data->end]))
		return (data->line[data->end]);
	data->start = data->end;
	return (0);
}
