/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:37:50 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/12 16:40:36 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(t_env **env, char **cmd)
{
	t_env	*tmp;
	int		i;

	i = 1;
	tmp = *env;
	while (cmd[i] && tmp)
	{
		if (!ft_strncmp((*env)->name, cmd[i], ft_strlen(cmd[i])))
		{
			*env = (*env)->next;
			ft_env_delone((*env)->previous);
		}
		else
		{
			ft_env_delone(ft_get_env(tmp, cmd[i]));
		}
		tmp = tmp->next;
	}
}
