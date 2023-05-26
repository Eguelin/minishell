/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:26:09 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/26 13:44:31 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_token(t_dlist **dlst, char *line, size_t *start, size_t *end)
{
	int	i;

	i = 0;
	if (ft_strchr("<>", line[*end]))
		i = ft_token_chevron(dlst, line, start, end);
	else if (ft_strchr("\"'", line[*end]))
		i = ft_token_quote(dlst, line, start, end);
	else if (line[*end] == '|')
		i = ft_token_pipe(dlst, line, start, end);
	else if (line[*end] == ' ')
		i = ft_token_space(dlst, line, start, end);
	else if (line[*end] == '$')
		i = ft_token_dollar(dlst, line, start, end);
	else
		i = ft_token_word(dlst, line, start, end);
	return (i);
}
