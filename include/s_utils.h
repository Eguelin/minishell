/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_utils.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:43:10 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/20 10:04:20 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_UTILS_H
# define S_UTILS_H

# define MALLOC_FAILED 200
# define SYNTAX_ERROR 201
# define PIPE_FAILED 202
# define FORK_FAILED 203

typedef struct s_minishell
{
	t_env	*env;
	t_lcmd	*lcmd;
	char	*prompt;
}	t_minishell;

#endif
