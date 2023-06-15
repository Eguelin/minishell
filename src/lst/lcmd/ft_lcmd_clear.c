/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lcmd_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:38:12 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/14 09:49:20 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lcmd_clear(t_lcmd **lcmd)
{
	t_lcmd	*tmp;

	if (!lcmd)
		return ;
	while (*lcmd)
	{
		tmp = (*lcmd)->next;
		ft_lcmd_delone(*lcmd);
		*lcmd = tmp;
	}
}
