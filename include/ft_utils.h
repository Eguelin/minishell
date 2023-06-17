/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:43:10 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/17 15:55:53 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

void		ft_ctrl_c_exec(int signum);
void		ft_ctrl_c(int signum);
void		ft_exit_minishell(t_minishell *data, int status);
t_minishell	*ft_get_data(t_minishell *data);
void		ft_init_minishell(t_minishell *data, char **env);
char		*ft_prompt(t_minishell *data);

#endif
