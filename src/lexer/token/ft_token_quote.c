/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:26:09 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/26 18:53:50 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_dlr_quote(t_dlist **dlst, char *str, size_t *start, size_t *end);

int	ft_token_quote(t_dlist **dlst, char *str, size_t *start, size_t *end)
{
	char	c;

	c = str[(*end)++];
	if (ft_add_token(dlst, str, *start, *end - *start))
		return (130);
	*start = *end;
	while (str[*end] && str[*end] != c)
	{
		if (c == '"' && str[*end] == '$')
		{
			if (ft_dlr_quote(dlst, str, start, end))
				return (131);
		}
		else if (str[*end] != c)
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

static int	ft_dlr_quote(t_dlist **dlst, char *str, size_t *start, size_t *end)
{
	if (ft_add_token(dlst, str, *start, *end - *start))
		return (1);
	*start = *end;
	if (ft_token_dollar(dlst, str, start, end))
		return (1);
	return (0);
}
