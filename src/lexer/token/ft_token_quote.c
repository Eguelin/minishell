/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:26:09 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/26 13:40:34 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_token_quote(t_dlist **dlst, char *str, size_t *start, size_t *end)
{
	char	c;

	c = str[*end];
	(*end)++;
	if (ft_add_token(dlst, str, *start, *end - *start))
		return (130);
	*start = *end;
	while (str[*end] && str[*end] != c)
	{
		if (c == '"' && str[*end] == '$')
			ft_token_dollar(dlst, str, start, end);
		if (str[*end] != c)
			(*end)++;
	}
	if (!str[*end])
		return (131);
	if (ft_add_token(dlst, str, *start, *end - *start))
		return (130);
	*start = (*end)++;
	if (ft_add_token(dlst, str, *start, *end - *start))
		return (130);
	*start = *end;
	return (0);
}
