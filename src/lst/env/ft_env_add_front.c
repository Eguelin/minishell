/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:38:26 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/17 20:01:24 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env_add_front(t_env **env, t_env *new)
{
	if (!env || !new)
		return ;
	*env = ft_env_first(*env);
	new->next = *env;
	if (*env)
		(*env)->previous = new;
	*env = new;
}
