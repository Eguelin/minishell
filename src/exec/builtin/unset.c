/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:37:50 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/21 12:37:56 by naterrie         ###   ########lyon.fr   */
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

static int	unset_check(char *cmd)
{
	int	i;

	i = 1;
	if (cmd[0] == '_' && (!cmd[1] || cmd[1] == '='))
		return (1);
	if (!ft_isalpha(cmd[0]))
	{
		ft_printf_error("%s: unset: %s: No numeric arguements\n", \
		ft_get_data(NULL)->name, cmd);
		return (1);
	}
	while (cmd[i] && cmd[i] != '=')
	{
		if (!ft_isalnum(cmd[i]) && cmd[i] == '=')
		{
			ft_printf_error("%s: unset: %s: No numeric arguements\n", \
			ft_get_data(NULL)->name, cmd);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_unset(t_env **env, char **cmd)
{
	int	i;
	int	error_value;

	error_value = 0;
	i = 0;
	while (cmd[i] && cmd[i][0] != '\0')
	{
		error_value = unset_check(cmd[i]);
		if (error_value == 0)
			ft_remove(env, cmd[i]);
		i++;
	}
	return (error_value);
}
