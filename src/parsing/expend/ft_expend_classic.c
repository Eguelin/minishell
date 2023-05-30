/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:10:37 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/30 16:28:54 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_expend_classic(t_data_token *data, char *content)
{
	t_data_token	data_var;

	data_var.token = data->token;
	data_var.line = content;
	data_var.end = 0;
	data_var.start = 0;
	data_var.type = data->type;
	while (content[data_var.end])
	{
		if (content[data_var.end] == ' ' && ft_token_space(&data_var))
			return (1);
		else if (ft_token_word(&data_var))
			return (1);
	}
	return (0);
}
