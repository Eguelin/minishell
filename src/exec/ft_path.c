/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:34:40 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/22 17:29:04 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_path(t_minishell *data)
{
	t_env	*path;

	ft_free_split(data->path);
	path = ft_get_env(data->env, "PATH");
	data->path = ft_split(path->content, ':');
	if (!data->path)
		return (MALLOC_FAILED);
	return (0);
}

static char	*ft_check_absolute_path(t_minishell *data)
{
	if (ft_strchr(data->lcmd->cmd[0], '/'))
	{
		if (!access(data->lcmd->cmd[0], X_OK))
			return (data->lcmd->cmd[0]);
		else if (!access(data->lcmd->cmd[0], F_OK))
		{
			ft_printf_error("%s: %s: Permission denied\n", \
			data->name, data->lcmd->cmd[0]);
			ft_exit_minishell(data, 126);
		}
		else
		{
			ft_printf_error("%s: %s: not found\n", \
			data->name, data->lcmd->cmd[0]);
			ft_exit_minishell(data, 127);
		}
	}
	return (NULL);
}

// eguelin@z4r6p5:/sgoinfre/goinfre/Perso/eguelin/projet/minishell$ ./m; echo $?
// bash: ./m: No such file or directory
// 127
// eguelin@z4r6p5:/sgoinfre/goinfre/Perso/eguelin/projet/minishell$ ./build/; echo $?
// bash: ./build/: Is a directory
// 126
// eguelin@z4r6p5:/sgoinfre/goinfre/Perso/eguelin/projet/minishell$ ./FILE; echo $?
// bash: ./FILE: Permission denied
// 126

static char	*ft_check_relative_path(t_minishell *data)
{
	char	*path;
	int		i;

	i = 0;
	while (data->path && data->path[i])
	{
		path = ft_strjoin_three(data->path[i], "/", data->lcmd->cmd[0]);
		if (!path)
			ft_exit_minishell(data, MALLOC_FAILED);
		if (!access(path, X_OK))
			return (path);
		free(path);
		i++;
	}
	ft_printf_error("%s: %s: not found\n", data->name, data->lcmd->cmd[0]);
	ft_exit_minishell(data, 127);
	return (NULL);
}

char	*ft_check_cmd(t_minishell *data)
{
	char	*path;

	path = ft_check_absolute_path(data);
	if (!path)
		path = ft_check_relative_path(data);
	return (path);
}
