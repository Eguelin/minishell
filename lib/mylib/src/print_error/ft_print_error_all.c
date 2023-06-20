/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error_all.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:38:59 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/20 16:19:38 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

static int	ft_print_error_all_2(char c, va_list arg);

int	ft_print_error_all(char c, va_list arg)
{
	int		size;
	char	*s;

	size = 0;
	if (c == 'c')
		size = ft_print_error_char(va_arg(arg, int));
	else if (c == 's')
	{
		s = va_arg(arg, char *);
		if (!s)
			size = ft_print_error_str("(null)");
		else
			size = ft_print_error_str(s);
	}
	else if (c == 'p')
		size = ft_print_error_address(va_arg(arg, long));
	else if (c == 'd' || c == 'i')
		size = ft_print_error_nbr(va_arg(arg, int));
	else if (c == 'u')
		size = ft_print_error_base(va_arg(arg, unsigned int), 10, \
		"0123456789");
	else
		size = ft_print_error_all_2(c, arg);
	return (size);
}

static int	ft_print_error_all_2(char c, va_list arg)
{
	int	size;

	size = 0;
	if (c == 'x')
		size = ft_print_error_base(va_arg(arg, unsigned int), 16, \
		"0123456789abcdef");
	else if (c == 'X')
		size = ft_print_error_base(va_arg(arg, unsigned int), 16, \
		"0123456789ABCDEF");
	else if (c == '%')
		size = ft_print_error_char('%');
	return (size);
}
