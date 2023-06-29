/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:01:41 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/29 12:18:46 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_check_file(t_minishell *data, t_token *file, int *in, int *out);
static int	ft_open_file(t_token *file, int *in, int *out);
static int	ft_print_heredoc(t_token *file, int *in);

int	ft_file(t_minishell *data)
{
	int	in;
	int	out;

	in = -1;
	out = -1;
	ft_close(&data->pipefd[0]);
	if (ft_check_file(data, data->lcmd->file, &in, &out))
	{
		g_error = 1;
		if (data->pid)
			return (1);
		ft_exit_minishell(data, 1);
	}
	if (in >= 0)
		ft_dup(in, STDIN_FILENO, data);
	if (out > 0 && data->pid)
		data->out = out;
	if (out >= 0 && !data->pid)
		ft_dup(out, STDOUT_FILENO, data);
	else if (data->lcmd->next && out < 0)
		ft_dup(data->pipefd[1], STDOUT_FILENO, data);
	else
		ft_close(&data->pipefd[1]);
	return (0);
}

static int	ft_check_file(t_minishell *data, t_token *file, int *in, int *out)
{
	while (file)
	{
		if (file->type < HERE_DOC_EX && !(file->type % 2))
			return (ft_printf_error("%s: ambiguous redirect\n", data->name), 1);
		else if (file->type < HERE_DOC_EX)
		{
			if (file->type == IN && access(file->content, F_OK))
				return (ft_printf_error("%s: %s: No such file or directory\n", \
				data->name, file->content), 1);
			else
				if (ft_open_file(file, in, out))
					return (ft_printf_error("%s: %s: Permission denied\n", \
					data->name, file->content), 1);
		}
		else if (!data->pid)
		{
			ft_close(in);
			if (ft_print_heredoc(file, in))
				return (1);
		}
		file = file->next;
	}
	return (0);
}

static int	ft_open_file(t_token *file, int *in, int *out)
{
	if (file->type == IN)
	{
		ft_close(in);
		*in = open(file->content, O_RDONLY);
		if (*in == -1)
			return (1);
	}
	else
	{
		ft_close(out);
		if (file->type == APP_END)
			*out = open(file->content, O_CREAT | O_WRONLY | O_APPEND, 0644);
		else
			*out = open(file->content, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (*out == -1)
			return (1);
	}
	return (0);
}

static int	ft_print_heredoc(t_token *file, int *in)
{
	*in = open(file->content, O_RDONLY);
	if (*in == -1)
		return (ft_printf_error("%s: Error opening temporary file\n", \
		ft_get_data(NULL)->name), unlink(file->content), 1);
	ft_dup(*in, STDIN_FILENO, ft_get_data(NULL));
	unlink(file->content);
	*in = -1;
	return (0);
}
