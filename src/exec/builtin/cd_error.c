/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:55:09 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/23 18:39:19 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void	cd_error(char *cmd, t_env *env)
{
	t_minishell	*data;

	(void) env;
	data = ft_get_data(NULL);
	if (access(cmd, F_OK))
		ft_printf_fd(2, "%s: cd: %s: Not a directory\n", \
		data->name, cmd);
	else
		ft_printf_fd(2, "%s: cd: %s:No such file or directory\n", \
		data->name, cmd);
}
