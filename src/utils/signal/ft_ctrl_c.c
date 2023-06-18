/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctrl_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 13:01:30 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/18 19:12:25 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_ctrl_c(int signum)
{
	(void)signum;
	g_error = 130;
	rl_on_new_line();
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\001\x1B[1;37m\002(\001\x1B[1;31m\002130\001\x1B[1;37m\002)", \
	1);
	rl_replace_line("", 0);
	rl_redisplay();
}
