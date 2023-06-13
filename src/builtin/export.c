/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:05:31 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/13 14:13:43 by naterrie         ###   ########lyon.fr   */
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
		tmp->content = ft_strdup(cpy->content);
	}
	else
		ft_env_add_back(env, cpy);
	return (0);
}

int	ft_export(t_env **env, char **cmd)
{
	int	i;

	i = 1;
	while (cmd[i])
	{
		if (add_env(env, cmd[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
