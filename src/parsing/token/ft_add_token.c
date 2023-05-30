/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:26:09 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/28 19:16:31 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_add_token(t_data_token *data)
{
	t_token	*new;
	char	*str;

	if (data->end - data->start == 0)
		return (0);
	else
	{
		str = ft_substr(data->line, data->start, data->end - data->start);
		if (!str)
			return (130);
	}
	new = ft_token_new(str, data->type);
	if (!new)
	{
		free(str);
		return (130);
	}
	ft_token_add_back(data->token, new);
	return (0);
}
