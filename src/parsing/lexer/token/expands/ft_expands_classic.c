/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expands_classic.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:10:37 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/14 18:09:09 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_expands_classic(t_data_token *data, char *content)
{
	t_data_token	data_var;

	data_var.token = data->token;
	data_var.line = content;
	data_var.end = 0;
	data_var.start = 0;
	data_var.type = data->type;
	while (content[data_var.end])
	{
		if (content[data_var.end] == ' ' && data->type >= IN)
		{
			ft_token_last(*data->token)->type += 1;
			return (0);
		}
		if (content[data_var.end] == ' ' && ft_token_space(&data_var))
			return (MALLOC_FAILED);
		else if (ft_token_word(&data_var))
			return (MALLOC_FAILED);
	}
	return (0);
}
