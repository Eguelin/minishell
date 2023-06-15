/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:49:23 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/14 17:14:54 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_token_new(char *content, int type)
{
	t_token	*token_new;

	token_new = malloc(sizeof(t_token));
	if (!token_new)
		return (NULL);
	token_new->content = content;
	token_new->type = type;
	token_new->previous = NULL;
	token_new->next = NULL;
	return (token_new);
}
