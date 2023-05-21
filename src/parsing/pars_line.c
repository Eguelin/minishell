/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:34:36 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/21 15:23:44 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dlist	*ft_cut_line(char *line)
{
	t_dlist	*lst;
	size_t	start;
	size_t	end;

	lst = NULL;
	start = 0;
	end = 0;
	while (line[end])
	{
		if (ft_split_token(&lst, line, &start, &end))
		{
			ft_dlstclear(&lst, free);
			return (NULL);
		}
	}
	ft_dup_token(&lst, line, start, end - start);
	return (lst);
}
