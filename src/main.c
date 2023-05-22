/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:30:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/22 15:30:40 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_prompt(int i);

int	main(int argc, char **argv, char **env)
{
	t_minishell	data;
	t_dlist		*dlst;
	t_dlist		*tmp;
	char		*line;
	int			i;

	(void)argc;
	(void)argv;
	dlst = NULL;
	i = 0;
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
			dlst = ft_lexer(line);
			tmp = dlst;
			while (tmp)
			{
				printf("%d : %s\n", i++, (char *)tmp->content);
				tmp = tmp->next;
			}
			ft_dlstclear(&dlst, free);
		}
		free(line);
	}
	return (0);
}

char	*ft_prompt(int i)
{
	if (i)
		return ("\033[1;31m➜  \033[1;36mminishell \033[0m");
	else
		return ("\033[1;32m➜  \033[1;36mminishell \033[0m");
}
