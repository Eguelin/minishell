/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctrl_c_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 13:01:30 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/20 17:30:22 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_ctrl_c_heredoc(int signum)
{
	if (signum == 2)
	{
		ft_token_clear(ft_get_ptr_token(NULL));
		ft_exit_minishell(ft_get_data(NULL), 130);
	}
}
