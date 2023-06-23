/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_chevron.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:26:09 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/23 17:29:40 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_token_chevron_type(t_data_token *data);

int	ft_token_chevron(t_data_token *data)
{
	if (ft_token_space(data))
		return (MALLOC_FAILED);
	if (ft_token_chevron_type(data))
		return (SYNTAX_ERROR);
	while (data->line[data->end] && \
	ft_strchr(" \t\n\v\f\r", data->line[data->end]))
		(data->end)++;
	if (!data->line[data->end])
		return (SYNTAX_ERROR);
	else if (ft_strchr("<>|", data->line[data->end]))
		return (SYNTAX_ERROR);
	data->start = data->end;
	return (0);
}

static int	ft_token_chevron_type(t_data_token *data)
{
	char	c;

	c = data->line[data->end];
	while (data->line[data->end] == c)
		(data->end)++;
	if (data->end - data->start == 1 && c == '<')
		data->type = IN;
	else if (data->end - data->start == 1)
		data->type = OUT;
	else if (data->end - data->start == 2 && c == '<')
		data->type = HERE_DOC_EX;
	else if (data->end - data->start == 2)
		data->type = APP_END;
	else if (data->end - data->start > 2)
		return (SYNTAX_ERROR);
	return (0);
}
