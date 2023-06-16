/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:43:55 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/16 09:10:08 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_env_to_tab(t_env *env)
{
	int		i;
	char	**tab;
	char	*var;

	i = 0;
	env = ft_env_first(env);
	tab = ft_calloc(sizeof(char *), ft_env_size(env) + 1);
	if (!tab)
		return (NULL);
	while (env)
	{
		if (env->content)
			var = ft_strjoin_three(env->name, "=", env->content);
		else
			var = ft_strdup(env->name);
		if (!var)
			return (ft_free_split(tab), NULL);
		tab[i] = var;
		env = env->next;
		i++;
	}
	return (tab);
}
