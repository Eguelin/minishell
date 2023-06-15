/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:26:09 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/15 07:55:36 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_add_token(t_data_token *data)
{
	t_token	*new;
	char	*str;

	str = ft_substr(data->line, data->start, data->end - data->start);
	if (!str)
		return (MALLOC_FAILED);
	new = ft_token_new(str, data->type);
	if (!new)
	{
		free(str);
		return (MALLOC_FAILED);
	}
	ft_token_add_back(data->token, new);
	return (0);
}
