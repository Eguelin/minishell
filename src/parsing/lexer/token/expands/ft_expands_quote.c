/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expands_quote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:10:37 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/09 14:52:02 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_expands_quote(t_data_token *data, char *content)
{
	t_token	*new;
	char	*str;

	str = ft_strdup(content);
	if (!str)
		return (1);
	new = ft_token_new(str, data->type);
	if (!new)
	{
		free(str);
		return (1);
	}
	ft_token_add_back(data->token, new);
	return (0);
}
