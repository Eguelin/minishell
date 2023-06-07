/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:30:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/07 19:30:00 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_pipe(t_pipe *t_pipe);
char	*ft_prompt(int i);

int	main(int argc, char **argv, char **env)
{
	t_minishell	data;
	char		*line;

	(void)argc;
	(void)argv;
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
			ft_parsing(&data, line);
		ft_print_pipe(data.pipe);
		ft_pipe_clear(&data.pipe);
		add_history(line);
	}
	ft_env_clear(&data.env);
	return (0);
}

void	ft_print_pipe(t_pipe *t_pipe)
{
	int		i;
	t_token	*file;

	file = NULL;
	while (t_pipe)
	{
		i = 0;
		printf("pipe :\n\tcmd : ");
		while (t_pipe->cmd && t_pipe->cmd[i])
			printf("%s, ", t_pipe->cmd[i++]);
		printf("\n\tfile : ");
		file = t_pipe->file;
		while (file)
		{
			printf("[ %s | %d ] ", file->content, file->type);
			file = file->next;
		}
		printf("\n");
		t_pipe = t_pipe->next;
	}
}

char	*ft_prompt(int i)
{
	if (i)
		return ("\033[1;31m➜  \033[1;36mminishell \033[0m");
	else
		return ("\033[1;32m➜  \033[1;36mminishell \033[0m");
}
