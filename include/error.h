/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:02:08 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/18 16:37:21 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define MALLOC_FAILED -1
# define SYNTAX_ERROR -2
# define PIPE_FAILED -3
# define FORK_FAILED -4

void	ft_error(t_minishell *data, int error);

#endif
