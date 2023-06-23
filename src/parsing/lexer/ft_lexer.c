/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:34:36 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/21 19:59:23 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
			return (error);
	}
	if (ft_fusion_line(*token))
		return (MALLOC_FAILED);
	ft_get_ptr_token(token);
	error = ft_heredoc(*token, env);
	if (error == 130)
		ft_putstr_fd("\n", 1);
	if (error)
		return (error);
	return (0);
}
