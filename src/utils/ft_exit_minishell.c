/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_minishell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:28:48 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/20 13:29:19 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit_minishell(t_minishell *data, int status)
{
	ft_env_clear(&data->env);
	ft_lcmd_clear(&data->lcmd);
	free(data->prompt);
	ft_free_split(data->path);
	rl_clear_history();
	exit(status);
}
