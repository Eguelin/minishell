/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_ copy 2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:38:12 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/22 19:43:16 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_file	*ft_file_new(char *name, int type)
{
	t_file	*file_new;

	file_new = malloc(sizeof(t_file));
	if (!file_new)
		return (NULL);
	file_new->name = name;
	file_new->type = type;
	file_new->next = NULL;
	return (file_new);
}
