/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:43:10 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/23 11:54:25 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../lib/mylib/include/mylib.h"
# include <fcntl.h>
# include <stdio.h>
# include <signal.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "mylib.h"
# include "s_lst.h"
# include "s_parsing.h"
# include "s_utils.h"
# include "ft_exec.h"
# include "ft_lst.h"
# include "ft_parsing.h"
# include "ft_utils.h"

extern int	g_error;

#endif
