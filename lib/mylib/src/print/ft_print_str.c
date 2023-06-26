/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:35:07 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/26 11:47:51 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int	ft_print_str(t_printf *data, char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (data->index == PF_BUFFER_SIZE && ft_write(data))
			return (-1);
		data->buf[data->index] = s[i];
		data->index++;
		i++;
	}
	return (0);
}
