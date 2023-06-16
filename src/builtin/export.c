/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:05:31 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/16 16:44:43 by naterrie         ###   ########lyon.fr   */
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
	if (!ft_isalpha(cmd[0]))
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
	return (0);
}
