/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_chevron.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:26:09 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/15 07:57:15 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_token_chevron(t_data_token *data)
{
	char	c;

	c = data->line[data->end];
	if (ft_token_space(data))
		return (MALLOC_FAILED);
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
		return (data->line[data->end - 1]);
	while (data->line[data->end] == ' ')
		(data->end)++;
	if (!data->line[data->end])
		return (SYNTAX_ERROR);
	else if (ft_strchr("<>|", data->line[data->end]))
		return (data->line[data->end]);
	data->start = data->end;
	return (0);
}
