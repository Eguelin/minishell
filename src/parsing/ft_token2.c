/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:26:09 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/23 16:10:38 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_token_chevron(t_dlist **lst, char *str, size_t *start, size_t *end)
{
	char	c;

	c = str[*end];
	if (ft_dup_token(lst, str, *start, *end - *start))
		return (130);
	*start = *end;
	while (str[*end] == c)
		(*end)++;
	if (*end - *start > 2)
		return (str[*end - 1]);
	if (ft_dup_token(lst, str, *start, *end - *start))
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

	c = str[*end];
	if (ft_dup_token(lst, str, *start, *end - *start))
		return (130);
	*start = (*end)++;
	if (ft_dup_token(lst, str, *start, *end - *start))
		return (130);
	*start = *end;
	while (str[*end] && str[*end] != c)
	{
		if (c == '"' && str[*end] == '$')
			ft_token_dollar(lst, str, start, end);
		if (str[*end] != c)
			(*end)++;
	}
	if (!str[*end])
		return (131);
	if (ft_dup_token(lst, str, *start, *end - *start))
		return (130);
	*start = (*end)++;
	if (ft_dup_token(lst, str, *start, *end - *start))
		return (130);
	*start = *end;
	return (0);
}

int	ft_token_pipe(t_dlist **lst, char *str, size_t *start, size_t *end)
{
	if (ft_dup_token(lst, str, *start, *end - *start))
		return (130);
	*start = *end;
	(*end)++;
	if (ft_dup_token(lst, str, *start, *end - *start))
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
	if (ft_dup_token(lst, str, *start, *end - *start))
		return (130);
	*start = *end;
	(*end)++;
	if (ft_dup_token(lst, str, *start, *end - *start))
		return (130);
	while (str[*end] == c)
		(*end)++;
	*start = *end;
	return (0);
}

int	ft_token_dollar(t_dlist **lst, char *str, size_t *start, size_t *end)
{
	if (ft_dup_token(lst, str, *start, *end - *start))
		return (130);
	*start = *end;
	(*end)++;
	while (ft_isalpha(str[*end]) || str[*end] == '_')
		(*end)++;
	if (ft_dup_token(lst, str, *start, *end - *start))
		return (130);
	*start = *end;
	return (0);
}
