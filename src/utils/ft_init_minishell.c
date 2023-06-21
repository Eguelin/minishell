/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_minishell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:42:57 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/21 16:33:48 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_minishell(t_minishell *data, char *argv, char **env)
{
	char	**temp;
	int		i;

	i = 0;
	data->lcmd = NULL;
	data->prompt = NULL;
	data->env = ft_set_env(env);
	data->path = NULL;
	data->pid = 1;
	data->pipefd[0] = -1;
	data->pipefd[1] = -1;
	temp = ft_split(argv, '/');
	if (!temp)
		ft_error(data, MALLOC_FAILED);
	while (temp[i])
		i++;
	data->name = temp[i - 1];
	temp[i - 1] = NULL;
	ft_free_split(temp);
	if (!data->name)
		ft_error(data, MALLOC_FAILED);
	if (!data->env)
		ft_error(data, MALLOC_FAILED);
	ft_get_data(data);
}
