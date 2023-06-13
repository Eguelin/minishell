/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:37:50 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/13 14:41:34 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_remove(t_env **env, char *cmd)
{
	t_env	*tmp;
	int		i;

	i = 1;
	tmp = *env;
	while (tmp)
	{
		if (!ft_strncmp((*env)->name, cmd, ft_strlen(cmd)))
		{
			if (!(*env)->next)
				ft_env_delone(*env);
			else
			{
				*env = (*env)->next;
				ft_env_delone((*env)->previous);
			}
		}
		else
		{
			ft_env_delone(ft_get_env(tmp, cmd));
		}
		tmp = tmp->next;
	}
}

void	ft_unset(t_env **env, char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i] && cmd[i][0] != '\0')
	{
		ft_remove(env, cmd[i]);
		i++;
	}
}
