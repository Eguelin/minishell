/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:48:25 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/13 14:45:28 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	change_pwd(t_env **env, char *path, char *cwd)
{
	t_env	*oldpwd;
	t_env	*pwd;

	oldpwd = ft_get_env(*env, "OLDPWD");
	pwd = ft_get_env(*env, "PWD");
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
	temp = ft_get_env(*env, "PWD");
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

static int	ft_cd_back(t_env **env)
{
	char	*oldpath;
	t_env	*temp;
	t_env	*old;
	char	*cmd;
	char	cwd[PATH_MAX];

	getcwd(cwd, sizeof(cwd));
	old = ft_get_env(*env, "OLDPWD");
	if (old->content)
		cmd = ft_strdup(old->content);
	else
		return (1);
	temp = ft_get_env(*env, "PWD");
	if (temp)
		oldpath = ft_strdup(temp->content);
	else
		oldpath = ft_strdup(cwd);
	if (chdir(cmd) != 0)
		return (free(oldpath), free(cmd), 1);
	getcwd(cwd, sizeof(cwd));
	change_pwd(env, oldpath, cwd);
	printf("%s\n", cwd);
	free(oldpath);
	free(cmd);
	return (0);
}

static int	ft_cd_home(t_env **env)
{
	char	*oldpath;
	t_env	*temp;
	t_env	*home;
	char	*cmd;
	char	cwd[PATH_MAX];

	getcwd(cwd, sizeof(cwd));
	home = ft_get_env(*env, "HOME");
	if (home)
		cmd = ft_strdup(home->content);
	else
		return (1);
	temp = ft_get_env(*env, "PWD");
	if (temp)
		oldpath = ft_strdup(temp->content);
	else
		oldpath = ft_strdup(cwd);
	if (chdir(cmd) != 0)
		return (free(oldpath), 1);
	getcwd(cwd, sizeof(cwd));
	change_pwd(env, oldpath, cwd);
	free(oldpath);
	free(cmd);
	return (0);
}

int	ft_cd(t_env **env, char **cmd)
{
	if (cmd[2])
		return (1);
	if (!cmd[1] || (cmd[1][0] == '~' && !cmd[1][1]))
	{
		if (ft_cd_home(env) == 1)
			return (1);
	}
	else if (strcmp(cmd[1], "-") == 0)
	{
		if (ft_cd_back(env) == 1)
			return (1);
	}
	else
	{
		if (check_path(env, cmd[1]) == 1)
			return (1);
	}
	return (0);
}
