/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ptr_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:57:35 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/18 17:56:51 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	**ft_get_ptr_token(t_token **token)
{
	static t_token	**token_ptr;

	if (token)
		token_ptr = token;
	return (token_ptr);
}
