/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:43:36 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/21 14:04:50 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

char	*ft_check_cmd(t_minishell *data);
void	ft_file(t_minishell *data);
int		ft_exec(t_minishell *data);
int		ft_get_path(t_minishell *data);

#endif
