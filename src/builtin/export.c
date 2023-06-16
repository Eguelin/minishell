/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:05:31 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/16 17:45:53 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	add_env(t_env **env, char *cmd)
{
	t_env	*cpy;
	t_env	*tmp;

	cpy = ft_pars_env_var(cmd);
	tmp = ft_get_env(*env, cpy->name);
	if (tmp)
	{
		free(tmp->content);
		tmp->content = cpy->content;
		cpy->content = NULL;
		ft_env_delone(cpy);
	}
	else
		ft_env_add_back(env, cpy);
	return (0);
}

static int	export_check(char *cmd)
{
	int	i;

	i = 1;
	if (cmd[0] == '_' && (!cmd[1] || cmd[1] == '='))
		return (1);
	if (!ft_isalpha(cmd[0]) && cmd[0] != '_')
	{
		ft_putstr_fd("export: No numeric arguements\n", 2);
		g_error = 1;
		return (1);
	}
	while (cmd[i] && cmd[i] != '=')
	{
		if (!ft_isalnum(cmd[i]) && cmd[i] == '=')
		{
			ft_putstr_fd("export: No numeric arguements\n", 2);
			g_error = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

static int	index_export(t_env *env, char *name)
{
	int	i;

	i = 0;
	env = ft_env_first(env);
	while (env)
	{
		if (ft_strncmp(env->name, name, ft_strlen(name) + 1) < 0)
			i++;
		env = env->next;
	}
	return (i);
}

static void	sort_export(t_env *env)
{
	t_env	**tab;
	int		i;

	i = 0;
	tab = ft_calloc(sizeof(t_env *), ft_env_size(env) + 1);
	if (!tab)
	{
		g_error = MALLOC_FAILED;
		return ;
	}
	while (env)
	{
		tab[index_export(env, env->name)] = env;
		env = env->next;
	}
	while (tab[i])
	{
		if (tab[i]->content == NULL)
			printf("declare -x %s\n", tab[i]->name);
		else if (tab[i]->name[0] != '_' || tab[i]->name[1])
			printf("declare -x %s=\"%s\"\n", tab[i]->name, tab[i]->content);
		i++;
	}
	free(tab);
}

int	ft_export(t_env **env, char **cmd)
{
	int	i;

	i = 1;
	while (cmd[i])
	{
		if (export_check(cmd[i]) == 0)
		{
			if (add_env(env, cmd[i]) == 1)
				return (1);
		}
		i++;
	}
	if (i == 1)
		sort_export(*env);
	return (0);
}
