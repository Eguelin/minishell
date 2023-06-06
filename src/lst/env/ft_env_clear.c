/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:32:26 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/17 20:07:40 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env_clear(t_env **env)
{
	t_env	*tmp;

	if (!env)
		return ;
	*env = ft_env_first(*env);
	while (*env)
	{
		tmp = (*env)->next;
		ft_env_delone(*env);
		*env = tmp;
	}
}
