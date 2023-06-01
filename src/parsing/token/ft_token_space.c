/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:26:09 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/31 13:11:12 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_token_space(t_data_token *data)
{
	t_token	*new;

	if (!data->type)
		return (0);
	data->type = ISOLATOR;
	new = ft_token_new(NULL, data->type);
	if (!new)
		return (130);
	ft_token_add_back(data->token, new);
	while (data->line[data->end] == ' ')
		(data->end)++;
	data->start = data->end;
	return (0);
}
