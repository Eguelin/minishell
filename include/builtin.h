/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:49:08 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/20 11:18:57 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

int	ft_export(t_env **env, char **cmd);
int	ft_unset(t_env **env, char **cmd);
int	ft_cd(t_env **env, char **cmd);
int	ft_exit(t_minishell *data);
int	ft_echo(char **cmd);
int	ft_env(t_env *env);
int	ft_pwd(void);

#endif
