/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_ copy 3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:38:12 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/22 19:43:46 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_file_add_back(t_file **file, t_file *new)
{
	if (!file || !new)
		return ;
	if (*file)
		ft_file_last(*file)->next = new;
	else
		*file = new;
}
