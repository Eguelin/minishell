/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:30:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/21 11:43:03 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_lcmd(t_lcmd *t_lcmd);
void	ft_print_token(t_token	*token);

int	g_error;

// void	ft_extest(t_minishell *data)
// {
// 	char	*cmd[2];
// 	pid_t	pid;
// 	pid_t	pid2;

// 	signal(SIGINT, ft_ctrl_c_exec);
// 	cmd[0] = "cat";
// 	cmd[1] = NULL;
// 	pid = fork();
// 	if (!pid)
// 	{
// 		signal(SIGINT, SIG_DFL);
// 		signal(SIGQUIT, SIG_DFL);
// 		execve("/usr/bin/cat", cmd, ft_env_to_tab(data->env));
// 	}
// 	pid2 = fork();
// 	if (!pid2)
// 	{
// 		signal(SIGINT, SIG_DFL);
// 		signal(SIGQUIT, SIG_DFL);
// 		exit(130);
// 		execve("/usr/bin/ls", cmd, ft_env_to_tab(data->env));
// 	}
// 	waitpid(pid, NULL, 0);
// 	waitpid(pid2, &g_error, 0);
// 	if (g_error != 2 && g_error != 131)
// 		g_error = WEXITSTATUS(g_error);
// 	else if (g_error == 2)
// 		g_error = 130;
// }

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
