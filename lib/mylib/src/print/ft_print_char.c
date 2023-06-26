/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:34:10 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/26 11:47:42 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int	ft_print_char(t_printf *data, char c)
{
	if (data->index == PF_BUFFER_SIZE && ft_write(data))
		return (-1);
	data->buf[data->index] = c;
	data->index++;
	return (0);
}
