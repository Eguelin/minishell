/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_ copy 4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:38:12 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/22 19:44:05 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_file	*ft_file_last(t_file *file)
{
	if (!file)
		return (NULL);
	while (file->next)
		file = file->next;
	return (file);
}
