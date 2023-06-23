/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:17:34 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/15 09:43:44 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_fill_lcmd(t_minishell *data, t_token *token_lcmd);
static int	ft_convert_cmd(t_lcmd *new_lcmd, t_token *token_lcmd);
static int	ft_cmd_size(t_token *token_lcmd);
static void	ft_take_file(t_lcmd *new_lcmd, t_token *token_lcmd);

int	ft_parsing(t_minishell *data, char *line)
{
	t_token	*token;
	t_token	*token_lcmd;
	int		error;

	token = NULL;
	error = ft_lexer(&token, data->env, line);
	if (error)
		return (ft_token_clear(&token), error);
	while (token)
	{
		token_lcmd = token;
		while (token && token->type > 0)
			token = token->next;
		if (token)
		{
			token->previous->next = NULL;
			token->previous = NULL;
			token = token->next;
			ft_token_delone(token->previous);
		}
		if (ft_fill_lcmd(data, token_lcmd))
			return (ft_token_clear(&token), ft_token_clear(&token_lcmd), \
			MALLOC_FAILED);
	}
	return (0);
}

static int	ft_fill_lcmd(t_minishell *data, t_token *token_lcmd)
{
	t_lcmd	*new_lcmd;

	new_lcmd = ft_lcmd_new();
	if (!new_lcmd)
		return (MALLOC_FAILED);
	if (ft_convert_cmd(new_lcmd, token_lcmd))
		return (ft_lcmd_delone(new_lcmd), MALLOC_FAILED);
	ft_take_file(new_lcmd, token_lcmd);
	ft_lcmd_add_back(&data->lcmd, new_lcmd);
	return (0);
}

static int	ft_convert_cmd(t_lcmd *new_lcmd, t_token *token_lcmd)
{
	int		size;

	size = ft_cmd_size(token_lcmd);
	if (!size)
		return (0);
	new_lcmd->cmd = malloc(sizeof(char *) * (size + 1));
	if (!new_lcmd->cmd)
		return (MALLOC_FAILED);
	size = 0;
	while (token_lcmd)
	{
		if (token_lcmd->type == 1)
		{
			new_lcmd->cmd[size] = token_lcmd->content;
			token_lcmd->content = NULL;
			size++;
		}
		token_lcmd = token_lcmd->next;
	}
	new_lcmd->cmd[size] = NULL;
	return (0);
}

static int	ft_cmd_size(t_token *token_lcmd)
{
	int	size;

	size = 0;
	while (token_lcmd)
	{
		if (token_lcmd->type == 1)
			size++;
		token_lcmd = token_lcmd->next;
	}
	return (size);
}

static void	ft_take_file(t_lcmd *new_lcmd, t_token *token_lcmd)
{
	t_token	*tmp;

	tmp = token_lcmd;
	while (tmp)
	{
		if (tmp->type == 1 && tmp->next)
		{
			tmp = tmp->next;
			ft_token_delone(tmp->previous);
			if (!tmp->previous)
				token_lcmd = tmp;
		}
		else if (tmp->type == 1)
		{
			if (!tmp->previous)
				token_lcmd = NULL;
			ft_token_delone(tmp);
			tmp = NULL;
		}
		else
			tmp = tmp->next;
	}
	new_lcmd->file = token_lcmd;
}
