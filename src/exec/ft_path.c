/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:34:40 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/24 19:15:00 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_check_absolute_path(t_minishell *data);
static char	*ft_check_relative_path(t_minishell *data);

int	ft_get_path(t_minishell *data)
{
	t_env	*path;

	ft_free_split(data->path);
	path = ft_get_env(data->env, "PATH");
	if (path)
	{
		data->path = ft_split(path->content, ':');
		if (!data->path)
			return (MALLOC_FAILED);
	}
	else
		data->path = NULL;
	return (0);
}

char	*ft_check_cmd(t_minishell *data)
{
	char	*path;

	path = ft_check_absolute_path(data);
	if (!path)
		path = ft_check_relative_path(data);
	return (path);
}

static char	*ft_check_absolute_path(t_minishell *data)
{
	struct stat	path_stat;

	if (!ft_strchr(data->lcmd->cmd[0], '/'))
		return (NULL);
	if (stat(data->lcmd->cmd[0], &path_stat))
	{
		ft_printf_error("%s: %s: No such file or directory\n", \
		data->name, data->lcmd->cmd[0]);
		ft_exit_minishell(data, 127);
	}
	if (S_ISDIR(path_stat.st_mode))
		ft_printf_error("%s: %s: Is a directory\n", \
		data->name, data->lcmd->cmd[0]);
	else if (S_ISREG(path_stat.st_mode))
	{
		if (!access(data->lcmd->cmd[0], X_OK))
			return (data->lcmd->cmd[0]);
		ft_printf_error("%s: %s: Permission denied\n", \
		data->name, data->lcmd->cmd[0]);
	}
	ft_exit_minishell(data, 126);
	return (NULL);
}

static char	*ft_check_relative_path(t_minishell *data)
{
	char		*path;
	int			i;
	struct stat	path_stat;

	i = 0;
	while (data->path && data->path[i])
	{
		path = ft_strjoin_three(data->path[i], "/", data->lcmd->cmd[0]);
		if (!path)
			ft_exit_minishell(data, MALLOC_FAILED);
		if (!stat(path, &path_stat) && S_ISREG(path_stat.st_mode))
		{
			if (!access(path, X_OK))
				return (path);
			ft_printf_error("%s: %s: Permission denied\n", \
			data->name, data->lcmd->cmd[0]);
			ft_exit_minishell(data, 126);
		}
		free(path);
		i++;
	}
	ft_printf_error("%s: command not found\n", data->lcmd->cmd[0]);
	ft_exit_minishell(data, 127);
	return (NULL);
}
