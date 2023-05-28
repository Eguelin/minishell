/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:38:12 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/28 14:23:54 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_token_add_back(t_token **token, t_token *new)
{
	t_token	*token_last;

	if (!token || !new)
		return ;
	if (*token)
	{
		token_last = ft_token_last(*token);
		token_last->next = new;
		new->previous = token_last;
	}
	else
		*token = new;
}
