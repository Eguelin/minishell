/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:22:47 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/20 16:19:51 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int	ft_print_error_str(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_print_error_char(s[i]);
		i++;
	}
	return (i);
}
