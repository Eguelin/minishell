/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:03:04 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/17 16:31:54 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

void	ft_dlstdelone(t_dlist *dlst, void (*del)(void*))
{
	if (!dlst || !del)
		return ;
	del(dlst->content);
	free(dlst);
}
