/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:30:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/23 13:38:32 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_error;

int	main(int argc, char **argv, char **env)
{
	t_minishell	data;
	char		*line;

	(void)argc;
	ft_init_minishell(&data, argv[0], env);
	while (1)
	{
		signal(SIGINT, ft_ctrl_c);
		signal(SIGQUIT, SIG_IGN);
		line = readline(ft_prompt(&data));
		if (!line)
		{
			ft_putstr_fd("exit\n", 1);
			ft_exit_minishell(&data, g_error);
		}
		if (line[0])
			add_history(line);
		ft_error(&data, ft_parsing(&data, line));
		if (data.lcmd)
			ft_error(&data, ft_exec(&data));
		ft_lcmd_clear(&data.lcmd);
	}
	return (0);
}
