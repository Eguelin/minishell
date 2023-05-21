/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:26:09 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/21 15:21:02 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	else if (line[*end] == '$')
		i = ft_token_dollar(lst, line, start, end);
	else
		(*end)++;
	if (i && i < 127)
		printf("minishell: syntax error near unexpected token `%c'\n", i);
	else if (i)
		printf("minishell: syntax error near unexpected token `newline'\n");
	return (i);
}

int	ft_dup_token(t_dlist **lst, char *str, size_t start, size_t size)
{
	t_dlist	*new;
	char	*str_2;

	printf("start = %ld, size = %ld;\n", start, size);
	if (size == 0)
		return (0);
	str_2 = ft_substr(str, start, size);
	if (!str_2)
		return (130);
	new = ft_dlstnew(str_2);
	if (!new)
	{
		free(str_2);
		return (130);
	}
	ft_dlstadd_back(lst, new);
	return (0);
}
