/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_chr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:47:58 by naterrie          #+#    #+#             */
/*   Updated: 2023/05/31 15:58:39 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_env_chr(t_env *env, char *name)
{
	while (env && ft_strncmp(env->name, name, ft_strlen(name) + 1))
		env = env->next;
	return (env);
}
