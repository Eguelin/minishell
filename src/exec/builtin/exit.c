/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:31:31 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/27 17:41:38 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_atoi_exit(const char *str, t_minishell *data);

static int	ft_check_exit_digit(t_minishell *data, char *cmd)
{
	int	i;

	i = 0;
	if ((cmd[i] == '-' || cmd[i] == '+') && ft_isdigit(cmd[i + 1]))
		i++;
	while (cmd[i])
	{
		if (!ft_isdigit(cmd[i]))
		{
			if ((i < 20 && cmd[0] != '-' \
			&& cmd[0] != '+') || (i < 21 && (cmd[0] == '-' || cmd[0] == '+')))
			{
				while (cmd[i] && ft_strchr(" \t\n\v\f\r", cmd[i]))
					i++;
				if (!cmd[i])
					break ;
			}
			ft_printf_error("%s: exit: %s: numeric argument required\n", \
			data->name, data->lcmd->cmd[1]);
			ft_exit_minishell(data, 2);
		}
		i++;
	}
	return (ft_atoi_exit(data->lcmd->cmd[1], data));
}

static void	check(t_minishell *data, const char *str)
{
	if (!ft_strncmp(str, "-9223372036854775808", 20))
		ft_exit_minishell(data, 0);
	ft_printf_error("%s: exit: %s: numeric argument required\n", \
	data->name, data->lcmd->cmd[1]);
	ft_exit_minishell(data, 2);
}

static int	ft_atoi_exit(const char *str, t_minishell *data)
{
	size_t	i;
	long	somme;
	int		neg;

	i = 0;
	neg = 1;
	somme = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		neg *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ((str[i] >= 48 && str[i] <= 57))
	{
		if (somme != (somme * 10 + (str[i] - '0')) / 10)
			return (check(data, str), 0);
		somme = somme * 10 + (str[i] - '0');
		i++;
	}
	return (somme * neg);
}

int	ft_exit(t_minishell *data)
{
	int	i;
	int	error_value;

	i = 0;
	ft_printf_fd(ft_get_data(NULL)->out, "exit\n");
	if (data->lcmd->cmd[1])
	{
		while (data->lcmd->cmd[1][i] \
		&& ft_strchr(" \t\n\v\f\r", data->lcmd->cmd[1][i]))
			i++;
		if (!data->lcmd->cmd[1][i])
		{
			ft_printf_error("%s: exit: %s: numeric argument required\n", \
			data->name, data->lcmd->cmd[1]);
			ft_exit_minishell(data, 2);
		}
		error_value = ft_check_exit_digit(data, data->lcmd->cmd[1] + i);
		if (data->lcmd->cmd[2])
			return (ft_printf_error("%s: exit: too many arguments\n", \
			data->name), 1);
	}
	else
		error_value = g_error;
	ft_exit_minishell(data, error_value);
	return (0);
}
