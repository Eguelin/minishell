/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lcmd_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:38:12 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/14 17:12:20 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lcmd	*ft_lcmd_new(void)
{
	t_lcmd	*lcmd_new;

	lcmd_new = malloc(sizeof(t_lcmd));
	if (!lcmd_new)
		return (NULL);
	lcmd_new->cmd = NULL;
	lcmd_new->file = NULL;
	lcmd_new->next = NULL;
	return (lcmd_new);
}
