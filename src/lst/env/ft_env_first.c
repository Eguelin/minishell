/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envfirst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:19:26 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/17 16:39:20 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_env_first(t_env *env)
{
	if (!env)
		return (NULL);
	while (env->previous)
		env = env->previous;
	return (env);
}
