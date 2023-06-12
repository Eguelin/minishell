/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:32:26 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/28 14:23:32 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_token_clear(t_token **token)
{
	t_token	*tmp;

	if (!token)
		return ;
	*token = ft_token_first(*token);
	while (*token)
	{
		tmp = (*token)->next;
		ft_token_delone(*token);
		*token = tmp;
	}
}
