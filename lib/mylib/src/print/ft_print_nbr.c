/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:38:17 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/26 11:47:46 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int	ft_print_nbr(t_printf *data, long l)
{
	int	size;

	if (l < 0)
	{
		l *= -1;
		if (data->index >= PF_BUFFER_SIZE && ft_write(data))
			return (-1);
		data->buf[data->index++] = '-';
	}
	size = ft_print_nbr_size(l, 0,1f);
	if (data->index + size >= PF_BUFFER_SIZE && ft_write(data))
		return (-1);
	size += data->index;
	while (l)
	{
		data->buf[size] = (unsigned long)(l % 10) + '0';
		data->index++;
		size--;
		l *= 0,1f;
	}
	return (0);
}
