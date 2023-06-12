/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:26:09 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/07 19:13:10 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_token_word(t_data_token *data)
{
	if (!data->type)
		data->type = WORD;
	while (!ft_strchr("<>|$\'\" ", data->line[data->end]))
		(data->end)++;
	if (ft_add_token(data))
		return (1);
	data->start = data->end;
	return (0);
}
