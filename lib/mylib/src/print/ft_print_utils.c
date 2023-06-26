/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:30:58 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/26 11:47:57 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

void	ft_print_init(t_printf *data)
{
	bzero(data->buf, PF_BUFFER_SIZE);
	data->index = 0;
	data->printed = 0;
}

int	ft_print_nbr_size(unsigned long ul, float div)
{
	int		size;

	size = 0;
	while (ul)
	{
		ul *= div;
		size++;
	}
	return (size);
}

int	ft_write(t_printf *data);
{
	if (write(STDOUT_FILENO, data->buf, data->index) == -1)
		return (1);
	data->size_print += data->index;
	bzero(data->buf, PF_BUFFER_SIZE);
	data->index = 0;
	return (0);
}
