/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:03:04 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/17 16:31:54 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env_delone(t_env *env)
{
	if (!env)
		return ;
	if (env->previous)
		env->previous->next = env->next;
	if (env->next)
		env->next->previous = env->previous;
	free(env->name);
	free(env->content);
	free(env);
}
