/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_chevron.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:26:09 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/26 13:40:25 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_token_chevron(t_dlist **dlst, char *str, size_t *start, size_t *end)
{
	char	c;

	c = str[*end];
	while (str[*end] == c)
		(*end)++;
	if (*end - *start > 2)
		return (str[*end - 1]);
	if (ft_add_token(dlst, str, *start, *end - *start))
		return (130);
	while (str[*end] == ' ')
		(*end)++;
	if (!str[*end])
		return (131);
	else if (ft_strchr("<>|", str[*end]))
		return (str[*end]);
	*start = *end;
	return (0);
}
