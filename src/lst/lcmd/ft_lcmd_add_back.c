/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lcmd_add_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:38:12 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/14 09:48:27 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lcmd_add_back(t_lcmd **lcmd, t_lcmd *new)
{
	if (!lcmd || !new)
		return ;
	if (*lcmd)
		ft_lcmd_last(*lcmd)->next = new;
	else
		*lcmd = new;
}
