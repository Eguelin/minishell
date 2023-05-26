/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:26:09 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/26 15:35:12 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_add_token(t_dlist **dlst, char *str, size_t start, size_t size)
{
	t_dlist	*new;
	char	*str_2;

	if (size == 0)
		return (0);
	else
	{
		str_2 = ft_substr(str, start, size);
		if (!str_2)
			return (130);
	}
	new = ft_dlstnew(str_2);
	if (!new)
	{
		free(str_2);
		return (130);
	}
	ft_dlstadd_back(dlst, new);
	return (0);
}
