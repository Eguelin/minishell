/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 01:43:55 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/26 11:48:07 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int	ft_printf(const char *fmt, ...);
{
	va_list ap;

	va_start(ap, fmt);
	while (*fmt)
	{
		//va_arg(ap, char *);
	}
	va_end(ap);
}
