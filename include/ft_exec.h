/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:43:36 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/24 13:10:39 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXEC_H
# define FT_EXEC_H

////////// [ builtin ] //////////
int		ft_export(t_env **env, char **cmd);
int		ft_unset(t_env **env, char **cmd);
int		ft_cd(t_minishell *data, char **cmd);
int		ft_exit(t_minishell *data);
int		ft_echo(char **cmd);
int		ft_env(t_env *env);
int		ft_pwd(void);

////////// [ exec ] //////////
char	*ft_check_cmd(t_minishell *data);
int		ft_file(t_minishell *data);
int		ft_exec(t_minishell *data);
int		ft_get_path(t_minishell *data);

#endif
