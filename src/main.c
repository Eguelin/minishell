/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:30:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/28 12:25:32 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_prompt(int i);

int		ft_expend_quote(t_dlist *var, char *content);
int		ft_expend_classic(t_dlist **top, t_dlist **var, char *content);
int		ft_expend_var(t_dlist **top, t_dlist **var, t_env *env, int i);

/*int	ft_expend(t_dlist **top, t_env *env)
{
	t_dlist	*var;

	var = *top;
	while (var)
	{
		if (((char *)var->content)[0] == '$')
		{
			var = var->next;
			while ()
			{
				if (var->content[0] == '$' && ft_expend_var(top, &var, env, 1))
					return (1);
			}
		}
		if (var->content[0] == '$' && ft_expend_var(top, &var, env, 0))
			return (1);
		if (var)
			var = var->next;
	}
	return (0);
}*/

int	ft_expend_var(t_dlist **top, t_dlist **var, t_env *env, int i)
{
	env = ft_env_chr(env, ((*var)->content) + 1);
	if (!env)
	{
		free((*var)->content);
		(*var)->content = NULL;
		return (0);
	}
	if (i && ft_expend_quote(*var, env->content))
		return (1);
	else if (!i && ft_expend_classic(top, var, env->content))
		return (1);
	return (0);
}

int	ft_expend_quote(t_dlist *var, char	*content)
{
	free(var->content);
	var->content = NULL;
	content = ft_strdup(content);
	if (!content)
		return (1);
	var->content = content;
	return (0);
}

int	ft_expend_classic(t_dlist **top, t_dlist **var, char *content)
{
	t_dlist	*previous;
	t_dlist	*next;
	size_t	start;
	size_t	end;

	previous = (*var)->previous;
	next = (*var)->next;
	start = 0;
	end = start;
	ft_dlstdelone(*var, free);
	*var = NULL;
	while (content[end])
	{
		if (content[end] == ' ' && ft_token_space(var, content, &start, &end))
			return (1);
		else if (ft_token_word(var, content, &start, &end))
			return (1);
	}
	ft_dlstadd_back(&previous, *var);
	ft_dlstadd_back(var, next);
	*top = ft_dlstfirst(*var);
	*var = next;
	return (0);
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
			ft_env_clear(&data.env);
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
			//ft_expend(&dlst, data.env);
			tmp = dlst;
			ft_expend_var(&dlst, &tmp, data.env, 0);
			printf("\n");
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
