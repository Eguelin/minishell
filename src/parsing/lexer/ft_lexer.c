/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:34:36 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/07 19:29:28 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_syntax_error(int i);

int	ft_lexer(t_token **token, t_env *env, char *line)
{
	t_data_token	data;
	int				error;

	data.token = token;
	data.line = line;
	data.end = 0;
	while (line[data.end] == ' ')
		(data.end)++;
	data.start = data.end;
	data.type = 0;
	while (line[data.end])
	{
		error = ft_get_token(&data, env);
		if (error)
			return (ft_syntax_error(error));
	}
	ft_fusion_line(*token);
	return (0);
}

int	ft_syntax_error(int error)
{
	if (error == '\n')
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
		return (2);
	}
	else if (error > 1)
	{
		printf("minishell: syntax error near unexpected token `%c'\n", error);
		return (2);
	}
	return (error);
}
