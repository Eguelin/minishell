/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:30:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/12 16:33:49 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_pipe(t_pipe *t_pipe);
void	ft_print_token(t_token	*token);
void	ft_free_minishell(t_minishell *data);

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
			exit(0);
		if (!ft_strncmp(line, "exit", 5))
		{
			free(line);
			break ;
		}
		else
			ft_error(ft_parsing(&data, line), &data);
		ft_print_pipe(data.pipe);
		ft_pipe_clear(&data.pipe);
		add_history(line);
	}
	ft_free_minishell(&data);
	return (0);
}

void	ft_print_pipe(t_pipe *t_pipe)
{
	int		i;

	while (t_pipe)
	{
		i = 0;
		printf("pipe :\n\tcmd : ");
		while (t_pipe->cmd && t_pipe->cmd[i])
			printf("%s, ", t_pipe->cmd[i++]);
		printf("\n\tfile : ");
		ft_print_token(t_pipe->file);
		printf("\n");
		t_pipe = t_pipe->next;
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

void	ft_free_minishell(t_minishell *data)
{
	ft_env_clear(&data->env);
	free(data->prompt);
}
