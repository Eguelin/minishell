/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:05:31 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/27 14:20:47 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_env(t_env **env, char *cmd)
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
}

static int	export_check(char *cmd)
{
	int	i;

	i = 1;
	if (ft_strlen(cmd) == 0 || cmd[1] == '=')
		return (1);
	if (cmd[0] == '-')
	{
		ft_printf_error("%s: unset: %s: invalid option\n", \
			ft_get_data(NULL)->name, cmd);
		return (3);
	}
	if (cmd[0] == '_')
		return (2);
	if (!ft_isalpha(cmd[0]) && cmd[0] != '_')
		return (1);
	while (cmd[i] && cmd[i] != '=')
	{
		if (!ft_isalnum(cmd[i]) && cmd[i] != '_')
			return (1);
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

static int	sort_export(t_env *env)
{
	t_env	**tab;
	int		i;

	i = 0;
	tab = ft_calloc(sizeof(t_env *), ft_env_size(env) + 1);
	if (!tab)
		return (MALLOC_FAILED);
	while (env)
	{
		tab[index_export(env, env->name)] = env;
		env = env->next;
	}
	while (tab[i])
	{
		if (tab[i]->content == NULL)
			ft_printf_fd(ft_get_data(NULL)->out, "declare -x %s\n", \
			tab[i]->name);
		else if (tab[i]->name[0] != '_' || tab[i]->name[1])
			ft_printf_fd(ft_get_data(NULL)->out, "declare -x %s=\"%s\"\n", \
			tab[i]->name, tab[i]->content);
		i++;
	}
	free(tab);
	return (0);
}

int	ft_export(t_env **env, char **cmd)
{
	int	i;
	int	error_value;

	i = 1;
	error_value = 0;
	while (cmd[i])
	{
		error_value = export_check(cmd[i]);
		if (error_value == 0)
			add_env(env, cmd[i]);
		else if (error_value == MALLOC_FAILED)
			return (error_value);
		else if (error_value == 1)
			return (ft_printf_error("%s: export: %s: not a valid identifier\n", \
			ft_get_data(NULL)->name, cmd[i]), 1);
		else if (error_value == 2)
			return (0);
		else if (error_value == 3)
			return (2);
		i++;
	}
	if (i == 1)
		sort_export(*env);
	return (error_value);
}
