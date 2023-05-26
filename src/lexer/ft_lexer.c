/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:34:36 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/26 14:28:33 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_syntax_error(int i);

int	ft_lexer(t_dlist **dlst, char *line)
{
	size_t	start;
	size_t	end;
	int		i;

	end = 0;
	while (line[end] == ' ')
		end++;
	start = end;
	while (line[end])
	{
		i = 0;
		i = ft_get_token(dlst, line, &start, &end);
		if (i)
			return (ft_syntax_error(i));
	}
	return (0);
}

int	ft_syntax_error(int i)
{
	if (i < 127)
		printf("minishell: syntax error near unexpected token `%c'\n", i);
	else if (i == 131)
		printf("minishell: syntax error near unexpected token `newline'\n");
	return (i);
}
