/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_utils.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:43:10 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/22 13:57:36 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_UTILS_H
# define S_UTILS_H

# define MALLOC_FAILED 200
# define SYNTAX_ERROR 201
# define PIPE_FAILED 202
# define FORK_FAILED 203
# define OPEN_FAILED 204

typedef struct s_minishell
{
	t_env	*env;
	t_lcmd	*lcmd;
	char	*prompt;
	char	**path;
	pid_t	pid;
	int		pipefd[2];
	char	*name;
	int		out;
}	t_minishell;

#endif
