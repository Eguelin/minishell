/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctrl_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 13:01:30 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/17 15:54:00 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_ctrl_c(int signum)
{
	if (signum == 2)
	{
		g_error = 130;
		ft_putstr_fd("\n", 1);
		ft_putstr_fd(ft_prompt(ft_get_data(NULL)), 1);
		rl_replace_line("", 0);
	}
}
