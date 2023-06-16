/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:30:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/16 15:00:41 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_lcmd(t_lcmd *t_lcmd);
void	ft_print_token(t_token	*token);

unsigned int	g_error;

int	main(int argc, char **argv, char **env)
{
	t_minishell	data;
	char		*line;

	(void)argc;
	(void)argv;
	ft_init_minishell(&data, env);
	while (1)
	{
		line = readline(ft_prompt(&data));
		if (!line)
			ft_exit_minishell(&data, g_error);
		ft_error(&data, ft_parsing(&data, line));
		ft_print_lcmd(data.lcmd);
		ft_lcmd_clear(&data.lcmd);
		add_history(line);
	}
	return (0);
}

void	ft_print_lcmd(t_lcmd *lcmd)
{
	int		i;

	while (lcmd)
	{
		i = 0;
		printf("lcmd :\n\tcmd : ");
		while (lcmd->cmd && lcmd->cmd[i])
			printf("%s, ", lcmd->cmd[i++]);
		printf("\n\tfile : ");
		ft_print_token(lcmd->file);
		printf("\n");
		lcmd = lcmd->next;
	}
}

void	ft_print_token(t_token	*token)
{
	while (token)
	{
		printf("[ %s | %d ] ", token->content, token->type);
		token = token->next;
	}
}
