/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:26:09 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/19 19:11:06 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_token_chevron(t_dlist **lst, char *str, size_t *start, size_t *end)
{
	char	c;

	c = str[*end];
	ft_token(lst, str, *start, *end - *start);
	*start = *end;
	while (str[*end] == c)
		(*end)++;
	ft_token(lst, str, *start, *end - *start);
	*start = *end;
}

void	ft_token_quote(t_dlist **lst, char *str, size_t *start, size_t *end)
{
	char	c;

	c = str[*end];
	ft_token(lst, str, *start, *end - *start);
	*start = *end;
	while (str[*end] == '\'' || str[*end] == '\"')
	{
		(*end)++;
		while (str[*end] && str[*end] != c)
			(*end)++;
		if (str[*end])
			(*end)++;
	}
	ft_token(lst, str, *start, *end - *start);
	*start = *end;
}

void	ft_token_pipe(t_dlist **lst, char *str, size_t *start, size_t *end)
{
	ft_token(lst, str, *start, *end - *start);
	*start = *end;
	(*end)++;
	ft_token(lst, str, *start, *end - *start);
	*start = *end;
}

void	ft_token_space(t_dlist **lst, char *str, size_t *start, size_t *end)
{
	char	c;

	c = str[*end];
	ft_token(lst, str, *start, *end - *start);
	*start = *end;
	while (str[*end] == c)
		(*end)++;
	*start = *end;
}

void	ft_token(t_dlist **lst, char *str, size_t start, size_t end)
{
	t_dlist	*new;
	char	*str_2;

	if (start == end || end == 0)
		return ;
	str_2 = ft_substr(str, start, end);
	if (!str_2)
		exit(1);
	new = ft_dlstnew(str_2);
	if (!new)
		exit(1);
	ft_dlstadd_back(lst, new);
}
