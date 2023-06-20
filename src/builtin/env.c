/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:35:55 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/20 10:37:08 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_env *env)
{
	while (env)
	{
		if (env->content != NULL)
			printf("%s=%s\n", env->name, env->content);
		env = env->next;
	}
	return (0);
}