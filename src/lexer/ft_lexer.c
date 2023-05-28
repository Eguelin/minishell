/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:34:36 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/28 19:16:12 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_syntax_error(int i);

int	ft_lexer(t_token **token, char *line)
{
	t_data_token	data;
	int				i;

	data.token = token;
	data.line = line;
	data.end = 0;
	while (line[data.end] == ' ')
		(data.end)++;
	data.start = 0;
	data.type = 0;
	while (line[data.end])
	{
		i = ft_get_token(&data);
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
