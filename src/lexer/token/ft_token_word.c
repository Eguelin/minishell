/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:26:09 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/26 13:40:48 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_token_word(t_dlist **dlst, char *str, size_t *start, size_t *end)
{
	while (!ft_strchr("<>|$\'\" ", str[*end]))
		(*end)++;
	if (ft_add_token(dlst, str, *start, *end - *start))
		return (130);
	*start = *end;
	return (0);
}
