/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:59:00 by naterrie          #+#    #+#             */
/*   Updated: 2023/06/15 16:38:02 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(void)
{
	char	cwd[PATH_MAX];

	ft_putstr_fd(getcwd(cwd, sizeof(cwd)), 1);
	printf("\n");
}
