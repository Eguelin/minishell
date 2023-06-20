/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:24:07 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/20 16:53:58 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int	ft_printf_error(const char *format, ...)
{
	va_list	larg;
	size_t	i;
	int		size;

	i = 0;
	size = 0;
	if (write(2, 0, 0) != 0 || !format)
		return (-1);
	va_start(larg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			size += ft_print_error_all(format[i + 1], larg);
		}
		else
			size += ft_print_error_char(format[i]);
		if (format[i + 1] && format[i] == '%')
			i ++;
		i++;
	}
	va_end(larg);
	return (size);
}
