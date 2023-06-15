/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expands_global.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:10:37 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/14 18:10:55 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_expands_global(t_data_token *data)
{
	t_token	*new;
	char	*str;

	str = ft_itoa(g_error);
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
