/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_ copy 3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:38:12 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/23 14:53:26 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pipe_add_back(t_pipe **pipe, t_pipe *new)
{
	if (!pipe || !new)
		return ;
	if (*pipe)
		ft_pipe_last(*pipe)->next = new;
	else
		*pipe = new;
}
