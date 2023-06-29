/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_delone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:03:04 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/29 13:32:50 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_token_delone(t_token *token)
{
	if (!token)
		return ;
	if (token->previous)
		token->previous->next = token->next;
	if (token->next)
		token->next->previous = token->previous;
	if (token->type > HERE_DOC_NO)
		close(token->type - HERE_DOC_NO);
	if (token->content && !ft_strncmp(token->content, "/var/tmp/herdoc", 15))
		unlink(token->content);
	free(token->content);
	free(token);
}
