/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:34:36 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/22 17:00:02 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dlist	*ft_lexer(char *line)
{
	t_dlist	*dlst;
	size_t	start;
	size_t	end;

	dlst = NULL;
	start = 0;
	end = 0;
	while (line[end])
	{
		if (ft_split_token(&dlst, line, &start, &end))
		{
			ft_dlstclear(&dlst, free);
			return (NULL);
		}
	}
	ft_dup_token(&dlst, line, start, end - start);
	return (dlst);
}
