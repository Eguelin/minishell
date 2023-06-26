/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:36:52 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/26 11:47:38 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int	ft_print_base(t_printf *data, unsigned long ul, int base, int type)
{
	int		size;
	float	div;
	static char* base_1 = "0123456789abcdef";
	static char* base_2 = "0123456789ABCDEF";

	div = 1 / base;
	size = ft_print_nbr_size(ul, div);
	if (data->index + size >= PF_BUFFER_SIZE && ft_write(data))
		return (-1);
	size += data->index;
	while (ul)
	{
		if (type)
			data->buf[size] = base_1[ul % base];
		else
			data->buf[size] = base_2[ul % base];
		data->index++;
		size--;
		ul *= div;
	}
	return (0);
}
