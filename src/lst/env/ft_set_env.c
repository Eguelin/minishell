/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:37:13 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/16 17:00:40 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*ft_increase_shlvl(char *shlvl);
static int		ft_check_presence(t_env **env, char *name);
static int		ft_complete_content(char *name, char **content, \
char pwd[PATH_MAX]);

t_env	*ft_set_env(char **env)
{
	int		i;
	t_env	*set_env;
	t_env	*new;

	i = 0;
	set_env = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "SHLVL=", 6))
			new = ft_pars_env_var(env[i]);
		else
			new = ft_increase_shlvl(env[i]);
		if (!new)
			return (ft_env_clear(&set_env), NULL);
		ft_env_add_back(&set_env, new);
		i++;
	}
	if (ft_check_presence(&set_env, "SHLVL"))
		return (ft_env_clear(&set_env), NULL);
	if (ft_check_presence(&set_env, "PWD"))
		return (ft_env_clear(&set_env), NULL);
	if (ft_check_presence(&set_env, "OLDPWD"))
		return (ft_env_clear(&set_env), NULL);
	return (set_env);
}

static t_env	*ft_increase_shlvl(char *shlvl)
{
	t_env	*new;
	char	*name;
	char	*content;

	name = ft_strdup("SHLVL");
	if (!name)
		return (NULL);
	content = ft_itoa(ft_atoi(shlvl + 6) + 1);
	if (!content)
		return (free(name), NULL);
	new = ft_env_new(name, content);
	if (!new)
		return (free(name), free(content), NULL);
	return (new);
}

static int	ft_check_presence(t_env **env, char *var)
{
	int		i;
	t_env	*tmp;
	char	*name;
	char	*content;
	char	pwd[PATH_MAX];

	i = 0;
	tmp = *env;
	if (!ft_strncmp(var, "PWD", 4) && !getcwd(pwd, sizeof(pwd)))
		return (ft_putstr_fd("Minishell: error retrieving current directory\n", \
		2), 0);
	while (tmp && ft_strncmp(tmp->name, var, ft_strlen(var) + 1))
		tmp = tmp->next;
	if (tmp)
		return (0);
	name = ft_strdup(var);
	if (!name)
		return (MALLOC_FAILED);
	if (ft_complete_content(name, &content, pwd))
		return (free(name), MALLOC_FAILED);
	tmp = ft_env_new(name, content);
	if (!tmp)
		return (free(name), free(content), MALLOC_FAILED);
	ft_env_add_back(env, tmp);
	return (0);
}

static int	ft_complete_content(char *name, char **content, char pwd[PATH_MAX])
{
	*content = "";
	if (!ft_strncmp(name, "SHLVL", 6))
		*content = ft_strdup("1");
	else if (!ft_strncmp(name, "PWD", 4))
		*content = ft_strdup(pwd);
	if (!*content)
	else if (!ft_strncmp(name, "OLDPWD", 7))
		*content = NULL;
	return (0);
}
