/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_minishell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:28:48 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/14 09:49:57 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit_minishell(t_minishell *data, int status)
{
	ft_env_clear(&data->env);
	ft_lcmd_clear(&data->lcmd);
	free(data->prompt);
	exit(status);
}
