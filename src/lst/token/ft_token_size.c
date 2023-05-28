/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:27:39 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/28 14:23:14 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_token_size(t_token *token)
{
	int	n;

	n = 0;
	token = ft_token_first(token);
	while (token)
	{
		token = token->next;
		n++;
	}
	return (n);
}
