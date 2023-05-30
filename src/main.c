/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:30:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/30 16:49:24 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_prompt(int i);

int	main(int argc, char **argv, char **env)
{
	t_minishell	data;
	t_token		*token;
	t_token		*tmp;
	char		*line;
	int			i;

	(void)argc;
	(void)argv;
	token = NULL;
	ft_init_minishell(&data, env);
	while (1)
	{
		line = readline(ft_prompt(0));
		if (!line)
			exit(0);
		if (!ft_strncmp(line, "exit", 5))
		{
			free(line);
			ft_env_clear(&data.env);
			exit(0);
		}
		else
		{
			if (ft_lexer(&token, data.env, line))
				ft_token_clear(&token);
			tmp = token;
			i = 1;
			while (tmp)
			{
				printf("%d\t:\t%s\t:\t%d\n", i++, tmp->content, tmp->type);
				tmp = tmp->next;
			}
			ft_token_clear(&token);
		}
		add_history(line);
	}
	ft_env_clear(&data.env);
	return (0);
}

char	*ft_prompt(int i)
{
	if (i)
		return ("\033[1;31m➜  \033[1;36mminishell \033[0m");
	else
		return ("\033[1;32m➜  \033[1;36mminishell \033[0m");
}
