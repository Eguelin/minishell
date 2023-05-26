/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:26:09 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/26 14:34:04 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_token_pipe(t_dlist **dlst, char *str, size_t *start, size_t *end)
{
	if (!(*dlst))
		return ('|');
	(*end)++;
	if (ft_add_token(dlst, str, *start, *end - *start))
		return (130);
	while (str[*end] == ' ')
		(*end)++;
	if (!str[*end])
		return ('|');
	else if (str[*end] == '|')
		return ('|');
	*start = *end;
	return (0);
}
