/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_utils.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:43:10 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/10 15:58:44 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_UTILS_H
# define S_UTILS_H

typedef struct s_minishell
{
	t_env	*env;
	t_pipe	*pipe;
	char	*prompt;
}	t_minishell;

#endif