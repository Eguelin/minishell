/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:49:23 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/17 16:35:04 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_env_new(char *name, char *content)
{
	t_env	*env_new;

	env_new = malloc(sizeof(t_env));
	if (!env_new)
		return (free(name), free(content), NULL);
	env_new->name = name;
	env_new->content = content;
	env_new->previous = NULL;
	env_new->next = NULL;
	return (env_new);
}
