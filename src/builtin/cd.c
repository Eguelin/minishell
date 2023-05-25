/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:48:25 by naterrie          #+#    #+#             */
/*   Updated: 2023/05/23 14:45:29 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	change_pwd(char **env, char *oldpath)
{
	int		i;
	int		j;
	char	cwd[PATH_MAX];
	char	*temp;

	j = 0;
	i = 0;
	temp = NULL;
	while (env[j] && ft_strncmp(env[j], "OLDPWD=", 7))
		j++;
	while (env[i] && ft_strncmp(env[i], "PWD=", 4))
		i++;
	if (env[i])
	{
		temp = ft_strjoin("OLDPWD=", oldpath);
		env[i] = ft_strjoin("PWD=", getcwd(cwd, sizeof(cwd)));
		if (env[j])
			env[j] = ft_strdup(temp);
	}
	else if (env[j])
		env[j] = ft_strjoin("OLDPWD=", oldpath);
	else
		return ;
	free(temp);
}

static int	absolute_path(char **env, char *cmd)
{
	int		i;
	int		j;
	char	*oldpath;
	char	cwd[PATH_MAX];

	i = 0;
	j = 0;
	while (env[i] && ft_strncmp(env[i], "PWD=", 4))
		i++;
	if (env[i])
	{
		while (env[i][j] && env[i][j] != '=')
			j++;
		j++;
		oldpath = ft_strdup(env[i] + j);
	}
	else
		oldpath = ft_strdup(getcwd(cwd, sizeof(cwd)));
	if (chdir(cmd) != 0)
		return (free(oldpath), 1);
	change_pwd(env, oldpath);
	return (free(oldpath), 0);
}

int	ft_cd(char **env, char **cmd)
{
	int		i;
	int		j;
	char	cwd[PATH_MAX];

	i = 0;
	j = 0;
	if (cmd[2] || !cmd[1])
		return (1);
	if (absolute_path(env, cmd[1]) == 1)
		return (1);
	while (env[i] && ft_strncmp(env[i], "PWD=", 4))
		i++;
	while (env[j] && ft_strncmp(env[j], "OLDPWD=", 7))
		j++;
	getcwd(cwd, sizeof(cwd));
	return (0);
}
