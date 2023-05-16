/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:43:10 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/16 15:56:40 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../lib/mylib/include/mylib.h"
# include <stdio.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_minishell
{
	t_list	*env;
}	t_minishell;

void	ft_init_minishell(t_minishell *data, char **env);

#endif
