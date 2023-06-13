/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:49:08 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/13 14:52:55 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

int		ft_export(t_env **env, char **cmd);
int		ft_cd(t_env **env, char **cmd);

void	ft_unset(t_env **env, char **cmd);
void	ft_echo(char **cmd);
void	ft_pwd(void);
void	ft_env(t_env *env);

#endif
