/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:48:25 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/21 12:35:42 by naterrie         ###   ########lyon.fr   */
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
			oldpwd->content = pwd->content;
			pwd->content = ft_strdup(cwd);
		}
		else
			oldpwd->content = path;
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

	oldpath = NULL;
	getcwd(cwd, sizeof(cwd));
	temp = ft_get_env(*env, "PWD");
	if (temp)
		oldpath = temp->content;
	else if (cwd[0])
		oldpath = ft_strdup(cwd);
	if (!oldpath && !temp && cwd[0])
		return (MALLOC_FAILED);
	if (chdir(cmd) != 0)
		return (1);
	getcwd(cwd, sizeof(cwd));
	change_pwd(env, oldpath, cwd);
	return (0);
}

static int	ft_cd_back(t_env **env)
{
	char	*oldpath;
	t_env	*temp;
	t_env	*old;
	char	*cmd;
	char	cwd[PATH_MAX];

	oldpath = NULL;
	getcwd(cwd, sizeof(cwd));
	old = ft_get_env(*env, "OLDPWD");
	if (old->content)
		cmd = old->content;
	else
		return (1);
	temp = ft_get_env(*env, "PWD");
	if (temp)
		oldpath = temp->content;
	else if (cwd[0])
		oldpath = ft_strdup(cwd);
	if (!oldpath && !temp && cwd[0])
		return (MALLOC_FAILED);
	if (chdir(cmd) != 0)
		return (1);
	getcwd(cwd, sizeof(cwd));
	change_pwd(env, oldpath, cwd);
	return (ft_putstr_fd(cwd, 1), ft_putstr_fd("\n", 1), 0);
}

static int	ft_cd_home(t_env **env)
{
	char	*oldpath;
	t_env	*temp;
	t_env	*home;
	char	*cmd;
	char	cwd[PATH_MAX];

	oldpath = NULL;
	getcwd(cwd, sizeof(cwd));
	home = ft_get_env(*env, "HOME");
	if (home)
		cmd = home->content;
	else
		return (1);
	temp = ft_get_env(*env, "PWD");
	if (temp)
		oldpath = temp->content;
	else if (cwd[0])
		oldpath = ft_strdup(cwd);
	if (!oldpath && !temp && cwd[0])
		return (MALLOC_FAILED);
	if (chdir(cmd) != 0)
		return (free(oldpath), 1);
	getcwd(cwd, sizeof(cwd));
	change_pwd(env, oldpath, cwd);
	return (0);
}

int	ft_cd(t_env **env, char **cmd)
{
	int	error_value;

	error_value = 0;
	if (cmd[1] && cmd[2])
	{
		ft_printf_error("%s: cd: too many arguments\n", ft_get_data(NULL)->name);
		return (1);
	}
	if (!cmd[1] || (cmd[1][0] == '~' && !cmd[1][1]))
		error_value = ft_cd_home(env);
	else if (strcmp(cmd[1], "-") == 0)
		error_value = ft_cd_back(env);
	else
		error_value = check_path(env, cmd[1]);
	if (error_value == 1)
		ft_printf_error("%s: cd: %s: No such file or directory\n", \
		ft_get_data(NULL)->name, cmd[1]);
	return (error_value);
}
