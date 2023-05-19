/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:34:36 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/19 19:10:04 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dlist	*ft_cut_line(char *line)
{
	t_dlist	*list;
	size_t	start;
	size_t	end;

	list = NULL;
	start = 0;
	end = 0;
	while (line[end])
	{
		if (ft_strchr("<>", line[end]))
			ft_token_chevron(&list, line, &start, &end);
		else if (ft_strchr("\"'", line[end]))
			ft_token_quote(&list, line, &start, &end);
		else if (line[end] == '|')
			ft_token_pipe(&list, line, &start, &end);
		else if (line[end] == ' ')
			ft_token_space(&list, line, &start, &end);
		else
			end++;
	}
	ft_token(&list, line, start, end - start);
	return (list);
}
