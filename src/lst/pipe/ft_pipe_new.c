/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:38:12 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/05 17:12:02 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_pipe	*ft_pipe_new(void)
{
	t_pipe	*pipe_new;

	pipe_new = malloc(sizeof(t_pipe));
	if (!pipe_new)
		return (NULL);
	pipe_new->cmd = NULL;
	pipe_new->file = NULL;
	pipe_new->next = NULL;
	return (pipe_new);
}
