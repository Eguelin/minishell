/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:34:36 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/20 17:13:38 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_split_token(t_dlist **lst, char *line, size_t *start, size_t *end);

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
	ft_token(&lst, line, start, end - start);
	return (lst);
}

int	ft_split_token(t_dlist **lst, char *line, size_t *start, size_t *end)
{
	int	i;

	i = 0;
	if (ft_strchr("<>", line[*end]))
		i = ft_token_chevron(lst, line, start, end);
	else if (ft_strchr("\"'", line[*end]))
		i = ft_token_quote(lst, line, start, end);
	else if (line[*end] == '|')
		i = ft_token_pipe(lst, line, start, end);
	else if (line[*end] == ' ')
		i = ft_token_space(lst, line, start, end);
	else
		(*end)++;
	if (i && i < 127)
		printf("minishell: syntax error near unexpected token `%c'\n", i);
	else if (i)
		printf("minishell: syntax error near unexpected token `newline'\n");
	return (i);
}
