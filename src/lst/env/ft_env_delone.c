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

void	ft_env_delone(t_env *env, void (*del)(void*))
{
	if (!env || !del)
		return ;
	if (env->previous)
		env->previous->next = env->next;
	if (env->next)
		env->next->previous = env->previous;
	del(env->name);
	del(env->content);
	free(env);
}
