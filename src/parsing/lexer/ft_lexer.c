/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:34:36 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/24 13:21:27 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_init_data_token(t_data_token *data, t_token **token, char *line);

int	ft_lexer(t_token **token, t_env *env, char *line)
{
	t_data_token	data;
	int				error;

	ft_init_data_token(&data, token, line);
	if (line[data.end] == ':' && \
	(!line[data.end + 1] || (line[data.end + 1] == ' ')))
		return (0);
	while (line[data.end])
	{
		if (line[data.end] == '#')
			break ;
		error = ft_get_token(&data, env);
		if (error)
			return (error);
	}
	if (ft_fusion_line(*token))
		return (MALLOC_FAILED);
	ft_get_ptr_token(token);
	error = ft_heredoc(*token, env);
	if (error)
		return (error);
	return (0);
}

static void	ft_init_data_token(t_data_token *data, t_token **token, char *line)
{
	data->token = token;
	data->line = line;
	data->end = 0;
	while (line[data->end] && ft_strchr(" \t\n\v\f\r", line[data->end]))
		(data->end)++;
	data->start = data->end;
	data->type = 0;
}
