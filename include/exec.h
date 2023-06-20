/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:43:36 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/20 15:47:51 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

char	*ft_check_cmd(t_minishell *data);

int		ft_exec(t_minishell *data);
int		ft_get_path(t_minishell *data);

#endif
