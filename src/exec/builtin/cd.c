/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:48:25 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/24 12:54:52 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_check_dir(t_minishell *data, char *dir);
static int	ft_cd_replace_env(t_env *oldpwd, t_env *pwd, \
char oldcwd[PATH_MAX], char cwd[PATH_MAX]);
static int	ft_cd_move(t_minishell *data, char *dir);

int	ft_cd(t_minishell *data, char **cmd)
{
	t_env	*oldpwd;
	t_env	*home;

	if (cmd[1] && cmd[2])
		return (ft_printf_error("%s: cd: too many arguments\n", data->name), \
		1);
	if (!cmd[1] || (cmd[1][0] == '~' && !cmd[1][1]))
	{
		home = ft_get_env(data->env, "HOME");
		if (home && home->content)
			return (ft_cd_move(data, home->content));
		else
			return (ft_printf_error("%s: cd: HOME not set\n", data->name), 1);
	}
	else if (cmd[1][0] == '-' && !cmd[1][1])
	{
		oldpwd = ft_get_env(data->env, "OLDPWD");
		if (oldpwd && oldpwd->content)
			return (ft_cd_move(data, oldpwd->content));
		else
			return (ft_printf_error("%s: cd: OLDPWD not set\n", data->name), 1);
	}
	else
		return (ft_cd_move(data, cmd[1]));
}

static int	ft_cd_move(t_minishell *data, char *dir)
{
	t_env	*oldpwd;
	t_env	*pwd;
	char	oldcwd[PATH_MAX];
	char	cwd[PATH_MAX];

	if (ft_check_dir(data, dir))
		return (1);
	oldpwd = ft_get_env(data->env, "OLDPWD");
	pwd = ft_get_env(data->env, "PWD");
	getcwd(oldcwd, sizeof(oldcwd));
	if (oldpwd && (oldpwd->content == dir))
		ft_printf_fd(ft_get_data(NULL)->out, "%s\n", dir);
	chdir(dir);
	getcwd(cwd, sizeof(cwd));
	if (ft_cd_replace_env(oldpwd, pwd, oldcwd, cwd))
		return (MALLOC_FAILED);
	return (0);
}

static int	ft_check_dir(t_minishell *data, char *dir)
{
	struct stat	path_stat;

	if (stat(dir, &path_stat))
	{
		ft_printf_error("%s: cd: %s: No such file or directory\n", \
		data->name, dir);
		return (1);
	}
	if (!S_ISDIR(path_stat.st_mode))
		ft_printf_error("%s: cd: %s: Not a directory\n", \
		data->name, dir);
	else
	{
		if (!access(dir, X_OK))
			return (0);
		ft_printf_error("%s: cd: %s: Permission denied\n", \
		data->name, dir);
	}
	return (1);
}

static int	ft_cd_replace_env(t_env *oldpwd, t_env *pwd, \
char oldcwd[PATH_MAX], char cwd[PATH_MAX])
{
	if (oldpwd)
		free(oldpwd->content);
	if (oldpwd && pwd)
		oldpwd->content = pwd->content;
	else if (oldpwd)
	{
		oldpwd->content = ft_strdup(oldcwd);
		if (!oldpwd->content)
			return (MALLOC_FAILED);
	}
	if (pwd)
	{
		if (!oldpwd)
			free(pwd->content);
		pwd->content = ft_strdup(cwd);
		if (!pwd->content)
			return (MALLOC_FAILED);
	}
	return (0);
}
