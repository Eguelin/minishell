/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:43:10 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/29 17:31:06 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

////////// [ signal ] //////////
void		ft_ctrl_c_exec(int signum);
void		ft_ctrl_c_heredoc(int signum);
void		ft_ctrl_c(int signum);

////////// [ utils ] //////////
void		ft_close(int *fd);
void		ft_dup(int fd, int fd2, t_minishell *data);
void		ft_error(t_minishell *data, int error);
void		ft_exit_minishell(t_minishell *data, int status);
t_minishell	*ft_get_data(t_minishell *data);
void		ft_init_minishell(t_minishell *data, char *argv, char **env);
int			ft_open_heredoc(t_token *heredoc, int *fd_tmp);
char		*ft_prompt(t_minishell *data);

#endif
