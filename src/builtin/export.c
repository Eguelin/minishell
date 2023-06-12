/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:05:31 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/12 16:40:02 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	add_env(t_env **env, char *cmd)
{
	char	**temp;
	t_env	*tmp;

	temp = ft_split(cmd, '=');
	if (!temp)
		return (1);
	tmp = ft_get_env(*env, temp[0]);
	if (tmp)
	{
		free(tmp->content);
		tmp->content = ft_strdup(temp[1]);
	}
	else
	{
		tmp = ft_env_new(temp[0], temp[1]);
		ft_env_add_back(env, tmp);
	}
	ft_free_split(temp);
	free(tmp);
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
