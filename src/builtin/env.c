/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:35:55 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/22 14:03:43 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_env *env)
{
	while (env)
	{
		if (env->content != NULL)
			ft_printf_fd(ft_get_data(NULL)->out, "%s=%s\n", \
			env->name, env->content);
		env = env->next;
	}
	return (0);
}
