/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:17:34 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/07 14:06:00 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_fill_pipe(t_minishell *data, t_token *token_pipe);
int		ft_convert_cmd(t_pipe *new_pipe, t_token *token_pipe);
int		ft_cmd_size(t_token *token_pipe);
void	ft_take_file(t_pipe *new_pipe, t_token *token_pipe);

int	ft_parsing(t_minishell *data, char *line)
{
	t_token	*token;
	t_token	*token_pipe;
	int		error;

	token = NULL;
	error = ft_lexer(&token, data->env, line);
	if (error)
		return (ft_token_clear(&token), error);
	while (token)
	{
		token_pipe = token;
		while (token && token->type > 0)
			token = token->next;
		if (token)
		{
			token->previous->next = NULL;
			token->previous = NULL;
			token = token->next;
			ft_token_delone(token->previous);
		}
		if (ft_fill_pipe(data, token_pipe))
			return (ft_token_clear(&token), ft_token_clear(&token_pipe), 1);
	}
	return (0);
}

int	ft_fill_pipe(t_minishell *data, t_token *token_pipe)
{
	t_pipe	*new_pipe;

	new_pipe = ft_pipe_new();
	if (!new_pipe)
		return (1);
	if (ft_convert_cmd(new_pipe, token_pipe))
		return (ft_pipe_delone(new_pipe), 1);
	ft_take_file(new_pipe, token_pipe);
	ft_pipe_add_back(&data->pipe, new_pipe);
	return (0);
}

int	ft_convert_cmd(t_pipe *new_pipe, t_token *token_pipe)
{
	int		size;

	size = ft_cmd_size(token_pipe);
	if (!size)
		return (0);
	new_pipe->cmd = malloc(sizeof(char *) * (size + 1));
	if (!new_pipe->cmd)
		return (1);
	size = 0;
	while (token_pipe)
	{
		if (token_pipe->type == 1)
		{
			new_pipe->cmd[size] = token_pipe->content;
			token_pipe->content = NULL;
			size++;
		}
		token_pipe = token_pipe->next;
	}
	new_pipe->cmd[size] = NULL;
	return (0);
}

int	ft_cmd_size(t_token *token_pipe)
{
	int	size;

	size = 0;
	while (token_pipe)
	{
		if (token_pipe->type == 1)
			size++;
		token_pipe = token_pipe->next;
	}
	return (size);
}

void	ft_take_file(t_pipe *new_pipe, t_token *token_pipe)
{
	t_token	*tmp;

	tmp = token_pipe;
	while (tmp)
	{
		if (tmp->type == 1 && tmp->next)
		{
			tmp = tmp->next;
			ft_token_delone(tmp->previous);
			if (!tmp->previous)
				token_pipe = tmp;
		}
		else if (tmp->type == 1)
		{
			if (!tmp->previous)
				token_pipe = NULL;
			ft_token_delone(tmp);
			tmp = NULL;
		}
		else
			tmp = tmp->next;
	}
	new_pipe->file = token_pipe;
}
