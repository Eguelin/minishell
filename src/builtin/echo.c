/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:51:19 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/20 11:30:45 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_option(char *str)
{
	int	i;

	i = 0;
	if (!str[i] || str[i] != '-' || str[i + 1] != 'n')
		return (0);
	i++;
	while (str[i] && str[i] == 'n')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

static void	ft_writestr(char **str)
{
	int	i;

	i = 0;
	while (str[i] && str[i + 1])
	{
		printf ("%s ", str[i]);
		i++;
	}
	printf ("%s", str[i]);
}

int	ft_echo(char **cmd)
{
	int	i;

	i = 1;
	if (!cmd[i])
	{
		printf("\n");
		return (0);
	}
	if (check_option(cmd[i]))
	{
		while (cmd[i] && check_option(cmd[i]))
			i++;
		if (cmd[i])
			ft_writestr(cmd + i);
		return (0);
	}
	ft_writestr(cmd + i);
	printf("\n");
	return (0);
}
