/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:49:08 by naterrie          #+#    #+#             */
/*   Updated: 2023/05/19 12:31:05 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "../lib/mylib/include/mylib.h"

int		ft_export(t_list **env, char **cmd);
int		ft_cd(char **env, char **cmd);

void	ft_echo(char **cmd);
void	ft_pwd(void);
void	ft_env(char **env);

#endif
