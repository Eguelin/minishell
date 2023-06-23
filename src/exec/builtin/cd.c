/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:48:25 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/23 18:47:54 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	change_pwd(t_env **env, char *path, char *cwd)
{
	t_env	*oldpwd;
	t_env	*pwd;

	oldpwd = ft_get_env(*env, "OLDPWD");
	pwd = ft_get_env(*env, "PWD");
	if (!oldpwd)
	{
		if (pwd)
		{
			free(pwd->content);
			pwd->content = ft_strdup(cwd);
		}
	}
	else
	{
		free(oldpwd->content);
		if (pwd && pwd->content)
		{
			oldpwd->content = pwd->content;
			pwd->content = ft_strdup(cwd);
		}
		else
			oldpwd->content = path;
	}
}

static int	check_path(t_env **env, char *path)
{
	char	cwd[PATH_MAX];
	char	*oldpath;
	t_env	*temp;

	getcwd(cwd, sizeof(cwd));
	temp = ft_get_env(*env, "PWD");
	if (temp && temp->content)
		oldpath = temp->content;
	else
		oldpath = ft_strdup(cwd);
	if (chdir(path) != 0)
		return (cd_error(path, *env), 1);
	getcwd(cwd, sizeof(cwd));
	change_pwd(env, path, cwd);
	return (0);
}

static int	ft_cd_home(t_env **env)
{
	t_env	*temp;

	temp = ft_get_env(*env, "HOME");
	if (temp && temp->content)
		return (check_path(env, temp->content));
	return (ft_printf_error("%s: cd: HOME not set\n", \
		ft_get_data(NULL)->name), 1);
}

static int	ft_cd_back(t_env **env)
{
	t_env	*temp;
	int		return_value;

	temp = ft_get_env(*env, "OLDPWD");
	if (temp && temp->content)
	{
		return_value = check_path(env, temp->content);
		if (return_value == 0)
			ft_printf_fd(ft_get_data(NULL)->out, "%s\n", temp->content);
		return (return_value);
	}
	return (ft_printf_error("%s: cd: OLDPWD not set\n", \
		ft_get_data(NULL)->name), 1);
}

int	ft_cd(t_env **env, char **cmd)
{
	int		error_value;
	t_env	*temp;

	error_value = 0;
	temp = NULL;
	if (cmd[1] && cmd[2])
		return (ft_printf_error("%s: cd: too many arguments\n", \
		ft_get_data(NULL)->name), 1);
	if (!cmd[1] || (cmd[1][0] == '~' && !cmd[1][1]))
		error_value = ft_cd_home(env);
	else if (strcmp(cmd[1], "-") == 0)
		error_value = ft_cd_back(env);
	else
		error_value = check_path(env, cmd[1]);
	return (error_value);
}
