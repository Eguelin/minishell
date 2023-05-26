/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:30:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/26 19:19:26 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_prompt(int i);

void	ft_scip_expend(t_dlist **dlst, int i);

t_dlist	*ft_chr_expend(t_dlist *dlst, int i)
{
	while (dlst)
	{
		ft_scip_expend(&dlst, i);
		if (dlst && ((char *)dlst->content)[0] == '$')
			return (dlst);
		else if (dlst)
			dlst = dlst->next;
	}
	return (NULL);
}

void	ft_scip_expend(t_dlist **dlst, int i)
{
	if (!ft_strncmp((*dlst)->content, "<<", 3))
	{
		while ((*dlst) && ft_strncmp((*dlst)->content, " ", 2))
			(*dlst) = (*dlst)->next;
	}
	else if (!ft_strncmp((*dlst)->content, "\'", 2))
	{
		(*dlst) = (*dlst)->next;
		while ((*dlst) && ft_strncmp((*dlst)->content, "\'", 2))
			(*dlst) = (*dlst)->next;
	}
	else if (!i && !ft_strncmp((*dlst)->content, "\"", 2))
	{
		(*dlst) = (*dlst)->next;
		while ((*dlst) && ft_strncmp((*dlst)->content, "\"", 2))
			(*dlst) = (*dlst)->next;
	}
	else if (!ft_strncmp((*dlst)->content, "$", 2))
		(*dlst) = (*dlst)->next;
}

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
	ft_init_minishell(&data, env);
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
			if (ft_lexer(&dlst, line))
				ft_dlstclear(&dlst, free);
			tmp = dlst;
			i = 1;
			while (tmp)
			{
				printf("%d\t: %s\n", i++, (char *)tmp->content);
				tmp = tmp->next;
			}
			ft_dlstclear(&dlst, free);
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
