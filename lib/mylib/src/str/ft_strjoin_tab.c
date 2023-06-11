/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 05:43:08 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/10 14:32:34 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

char	*ft_strjoin_tab(char **tab)
{
	size_t	size;
	int		i;
	char	*str;

	size = 0;
	i = 0;
	while (tab[i])
		size += ft_strlen(tab[i++]);
	str = ft_calloc(sizeof(char), size + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (tab[i])
		ft_strlcat(str, tab[i++], size + 1);
	return (str);
}
