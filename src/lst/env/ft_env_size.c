/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:27:39 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/17 18:36:54 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env_size(t_env *env)
{
	int	n;

	n = 0;
	env = ft_env_first(env);
	while (env)
	{
		env = env->next;
		n++;
	}
	return (n);
}
