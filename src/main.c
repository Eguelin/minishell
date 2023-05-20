/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:30:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/20 16:52:25 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_prompt(int i);

int	main(int argc, char **argv, char **env)
{
	t_minishell	data;
	t_dlist		*lst;
	t_dlist		*tmp;
	char		*line;

	(void)argc;
	(void)argv;
	lst = NULL;
	ft_init_minishell(&data, env);
	ft_lstclear(&data.env, free);
	while (1)
	{
		line = readline(ft_prompt(0));
		if (!line)
			exit(0);
		if (!ft_strncmp(line, "exit", 5))
		{
			free(line);
			exit(0);
		}
		else
		{
			lst = ft_cut_line(line);
			tmp = lst;
			while (tmp)
			{
				printf("%s\n", (char *)tmp->content);
				tmp = tmp->next;
			}
			ft_dlstclear(&lst, free);
		}
		free(line);
	}
	return (0);
}

char	*ft_prompt(int i)
{
	if (i)
		return ("\033[1;31m➜  \033[1;36mminishell \033[1;34m"\
		"git:(\033[1;31mparsing-testing\033[1;34m) \033[1;33m✗ \033[0m");
	else
		return ("\033[1;32m➜  \033[1;36mminishell \033[1;34m"\
		"git:(\033[1;31mparsing-testing\033[1;34m) \033[1;33m✗ \033[0m");
}
