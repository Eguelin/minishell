/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_minishell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:42:57 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/21 15:12:18 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_minishell(t_minishell *data, char **env)
{
	data->lcmd = NULL;
	data->prompt = NULL;
	data->env = ft_set_env(env);
	data->path = NULL;
	data->pipefd[0] = -1;
	data->pipefd[1] = -1;
	if (!data->env)
		ft_error(data, MALLOC_FAILED);
	ft_get_data(data);
}
