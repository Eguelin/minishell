/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:27:27 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/10 14:28:16 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_get_env(t_env *env, char *name)
{
	while (env && ft_strncmp(env->name, name, ft_strlen(name) + 1))
		env = env->next;
	return (env);
}
