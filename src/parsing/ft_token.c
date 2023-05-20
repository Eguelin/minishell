/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:26:09 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/20 17:14:16 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_token_chevron(t_dlist **lst, char *str, size_t *start, size_t *end)
{
	char	c;

	c = str[*end];
	if (ft_token(lst, str, *start, *end - *start))
		return (130);
	*start = *end;
	while (str[*end] == c)
		(*end)++;
	if (*end - *start > 2)
		return (str[*end - 1]);
	if (ft_token(lst, str, *start, *end - *start))
		return (130);
	while (str[*end] == ' ')
		(*end)++;
	if (!str[*end])
		return (131);
	else if (ft_strchr("<>|", str[*end]))
		return (str[*end]);
	*start = *end;
	return (0);
}

int	ft_token_quote(t_dlist **lst, char *str, size_t *start, size_t *end)
{
	char	c;

	if (ft_token(lst, str, *start, *end - *start))
		return (130);
	*start = *end;
	while ((str[*end] == '\'' || str[*end] == '\"') && str[*end])
	{
		c = str[*end];
		(*end)++;
		while (str[*end] && str[*end] != c)
			(*end)++;
		if (!str[*end])
			return (131);
		(*end)++;
	}
	if (ft_token(lst, str, *start, *end - *start))
		return (130);
	*start = *end;
	return (0);
}

int	ft_token_pipe(t_dlist **lst, char *str, size_t *start, size_t *end)
{
	if (ft_token(lst, str, *start, *end - *start))
		return (130);
	*start = *end;
	(*end)++;
	if (ft_token(lst, str, *start, *end - *start))
		return (130);
	while (str[*end] == ' ')
		(*end)++;
	if (!str[*end])
		return ('|');
	else if (str[*end] == '|')
		return ('|');
	*start = *end;
	return (0);
}

int	ft_token_space(t_dlist **lst, char *str, size_t *start, size_t *end)
{
	char	c;

	c = str[*end];
	if (ft_token(lst, str, *start, *end - *start))
		return (130);
	*start = *end;
	while (str[*end] == c)
		(*end)++;
	*start = *end;
	return (0);
}

int	ft_token(t_dlist **lst, char *str, size_t start, size_t end)
{
	t_dlist	*new;
	char	*str_2;

	if (start == end || end == 0)
		return (0);
	str_2 = ft_substr(str, start, end);
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
