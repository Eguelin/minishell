/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_ copy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:38:12 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/23 14:54:24 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pipe_clear(t_pipe **pipe, void (*del)(void*))
{
	t_pipe	*tmp;

	if (!pipe || !del)
		return ;
	while (*pipe)
	{
		tmp = (*pipe)->next;
		ft_pipe_delone(*pipe, del);
		*pipe = tmp;
	}
}
