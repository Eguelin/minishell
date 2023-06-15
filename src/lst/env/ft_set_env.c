/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:37:13 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/15 16:10:15 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*ft_increase_shlvl(char *shlvl);
static int		ft_check_shelvl(t_env **set_env, char **env);
static int		ft_check_pwd(t_env **set_env, char **env);
static int		ft_check_oldpwd(t_env **set_env, char **env);

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
	if (ft_check_shelvl(&set_env, env))
		return (ft_env_clear(&set_env), NULL);
	if (ft_check_pwd(&set_env, env))
		return (ft_env_clear(&set_env), NULL);
	if (ft_check_oldpwd(&set_env, env))
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

static int	ft_check_shelvl(t_env **set_env, char **env)
{
	t_env	*new;
	char	*name;
	char	*content;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "SHLVL=", 6))
		i++;
	if (env[i])
		return (0);
	name = ft_strdup("SHLVL");
	if (!name)
		return (MALLOC_FAILED);
	content = ft_strdup("1");
	if (!content)
		return (free(name), MALLOC_FAILED);
	new = ft_env_new(name, content);
	if (!new)
		return (free(name), free(content), MALLOC_FAILED);
	ft_env_add_back(set_env, new);
	return (0);
}

static int	ft_check_pwd(t_env **set_env, char **env)
{
	t_env	*new;
	char	*name;
	char	*content;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PWD=", 4))
		i++;
	if (env[i])
		return (0);
	name = ft_strdup("PWD");
	if (!name)
		return (MALLOC_FAILED);
	content = getcwd(NULL, 0);
	if (!content)
		return (free(name), MALLOC_FAILED);
	new = ft_env_new(name, content);
	if (!new)
		return (free(name), free(content), MALLOC_FAILED);
	ft_env_add_back(set_env, new);
	return (0);
}

static int	ft_check_oldpwd(t_env **set_env, char **env)
{
	t_env	*new;
	char	*name;
	char	*content;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "OLDPWD=", 7))
		i++;
	if (env[i])
		return (0);
	name = ft_strdup("OLDPWD");
	if (!name)
		return (MALLOC_FAILED);
	content = NULL;
	new = ft_env_new(name, content);
	if (!new)
		return (free(name), MALLOC_FAILED);
	ft_env_add_back(set_env, new);
	return (0);
}
