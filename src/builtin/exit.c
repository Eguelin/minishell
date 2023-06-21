/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:31:31 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/21 17:15:23 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_check_exit_digit(t_minishell *data)
{
	int	i;

	i = 0;
	while (data->lcmd->cmd[1][i])
	{
		if (!ft_isdigit(data->lcmd->cmd[1][i]) || i > 20)
		{
			ft_printf_error("%s: exit: %s: numeric argument required\n", \
			data->name, data->lcmd->cmd[i + 1]);
			ft_exit_minishell(data, 2);
		}
		i++;
	}
	return (ft_atoi(data->lcmd->cmd[1]));
}

int	ft_exit(t_minishell *data)
{
	int	i;
	int	error_value;

	i = 0;
	error_value = 0;
	printf("exit\n");
	while (data->lcmd->cmd[i])
		i++;
	if (i > 2)
	{
		ft_printf_error("%s: exit: too many arguments\n", data->name);
		return (1);
	}
	i = 0;
	if (data->lcmd->cmd[1])
		error_value = ft_check_exit_digit(data);
	else
		error_value = g_error;
	ft_exit_minishell(data, error_value);
	return (0);
}
