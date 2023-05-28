/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_chr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:27:27 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/27 16:53:12 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_env_chr(t_env *env, char *name)
{
	while (env && ft_strncmp(env->name, name, ft_strlen(name) + 1))
		env = env->next;
	return (env);
}
