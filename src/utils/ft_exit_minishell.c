/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_minishell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:28:48 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/21 16:05:28 by eguelin          ###   ########lyon.fr   */
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
	ft_close(&data->pipefd[0]);
	ft_close(&data->pipefd[1]);
	close(0);
	if (!data->pid)
		close(1);
	free(data->name);
	exit(status);
}
