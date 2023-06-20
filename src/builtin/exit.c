/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:31:31 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/20 13:49:11 by naterrie         ###   ########lyon.fr   */
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
			ft_putstr_fd("exit: numeric argument required\n", 2);
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
	printf("salut\n");
	error_value = 0;
	while (data->lcmd->cmd[i])
		i++;
	if (i > 2)
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		return (1);
	}
	i = 0;
	if (data->lcmd->cmd[1])
		error_value = ft_check_exit_digit(data);
	ft_exit_minishell(data, error_value);
	return (0);
}
