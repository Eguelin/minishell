/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:37:50 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/27 14:24:51 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_remove(t_env **env, char *cmd)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (!ft_strncmp((*env)->name, cmd, ft_strlen(cmd)))
		{
			if (!(*env)->next)
				ft_env_clear(env);
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
	if (cmd[i] == '=')
		return (1);
	return (0);
}

int	ft_unset(t_env **env, char **cmd)
{
	int	i;
	int	error_value;

	error_value = 0;
	i = 0;
	while (cmd[i])
	{
		error_value = unset_check(cmd[i]);
		if (error_value == 0)
			ft_remove(env, cmd[i]);
		else if (error_value == 1)
		{
			ft_printf_error("%s: unset: %s: not a valid identifier\n", \
			ft_get_data(NULL)->name, cmd[i]);
			return (1);
		}
		else if (error_value == 2)
			return (0);
		else if (error_value == 3)
			return (2);
		i++;
	}
	return (error_value);
}
