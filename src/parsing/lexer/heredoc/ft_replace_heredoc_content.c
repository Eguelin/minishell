/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_heredoc_content.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 10:24:30 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/18 10:25:26 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_replace_heredoc_content(t_token *token, t_token *heredoc)
{
	free(token->content);
	if (heredoc)
		token->content = heredoc->content;
	else
		token->content = NULL;
}
