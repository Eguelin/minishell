/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:48:25 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/06 14:39:25 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	change_pwd(t_env **env, char *path, char *cwd)
{
	t_env	*oldpwd;
	t_env	*pwd;

	oldpwd = ft_env_chr(*env, "OLDPWD");
	pwd = ft_env_chr(*env, "PWD");
	if (oldpwd)
	{
		free(oldpwd->content);
		if (pwd)
		{
			oldpwd->content = ft_strdup(pwd->content);
			free(pwd->content);
			pwd->content = ft_strdup(cwd);
		}
		else
			oldpwd->content = ft_strdup(path);
	}
	else
	{
		if (pwd)
		{
			free(pwd->content);
			pwd->content = ft_strdup(cwd);
		}
	}
}

static int	check_path(t_env **env, char *cmd)
{
	char	*oldpath;
	t_env	*temp;
	char	cwd[PATH_MAX];

	getcwd(cwd, sizeof(cwd));
	temp = ft_env_chr(*env, "PWD");
	if (temp)
		oldpath = ft_strdup(temp->content);
	else
		oldpath = ft_strdup(cwd);
	if (chdir(cmd) != 0)
		return (free(oldpath), 1);
	getcwd(cwd, sizeof(cwd));
	change_pwd(env, oldpath, cwd);
	free(oldpath);
	return (0);
}

int	ft_cd(t_env **env, char **cmd)
{
	if (check_path(env, cmd[1]) == 1)
		return (1);
	return (0);
}

