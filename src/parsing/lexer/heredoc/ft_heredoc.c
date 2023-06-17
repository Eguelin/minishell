/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:09:03 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/17 18:41:15 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_heredoc(t_token *token)
{
	int	error;

	error = 0;
	while (token)
	{
		if (token->type == HERE_DOC_EX)
			error = ft_heredoc_expands(token);
		else if (token->type == HERE_DOC_NO)
			error = ft_heredoc_no_expans(token);
		if (error)
			return (error);
		token = token->next;
	}
	return (0);
}
