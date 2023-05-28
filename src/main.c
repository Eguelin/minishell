/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:30:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/28 19:10:11 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_prompt(int i);

// int		ft_expend_quote(t_token *var, char *content);
// int		ft_expend_classic(t_token **top, t_token **var, char *content);
// int		ft_expend_var(t_token **top, t_token **var, t_env *env, int i);

// int	ft_expend(t_token **top, t_env *env)
// {
// 	t_token	*var;

// 	var = *top;
// 	while (var)
// 	{
// 		if (((char *)var->content)[0] == '$')
// 		{
// 			var = var->next;
// 			while ()
// 			{
// 				if (var->content[0] == '$' && ft_expend_var(top, &var, env, 1))
// 					return (1);
// 			}
// 		}
// 		if (var->content[0] == '$' && ft_expend_var(top, &var, env, 0))
// 			return (1);
// 		if (var)
// 			var = var->next;
// 	}
// 	return (0);
// }

// int	ft_expend_var(t_token **top, t_token **var, t_env *env, int i)
// {
// 	env = ft_env_chr(env, ((*var)->content) + 1);
// 	if (!env)
// 	{
// 		free((*var)->content);
// 		(*var)->content = NULL;
// 		return (0);
// 	}
// 	if (i && ft_expend_quote(*var, env->content))
// 		return (1);
// 	else if (!i && ft_expend_classic(top, var, env->content))
// 		return (1);
// 	return (0);
// }

// int	ft_expend_quote(t_token *var, char	*content)
// {
// 	free(var->content);
// 	var->content = NULL;
// 	content = ft_strdup(content);
// 	if (!content)
// 		return (1);
// 	var->content = content;
// 	return (0);
// }

// int	ft_expend_classic(t_token **top, t_token **var, char *content)
// {
// 	t_token	*previous;
// 	t_token	*next;
// 	size_t index[2];

// 	previous = (*var)->previous;
// 	next = (*var)->next;
// 	index[0] = 0;
// 	index[1] = index[0];
// 	ft_token_delone(*var);
// 	*var = NULL;
// 	while (content[index[1]])
// 	{
// 		if (content[index[1]] == ' ' && ft_token_space(var, content, index))
// 			return (1);
// 		else if (ft_token_word(var, content, index))
// 			return (1);
// 	}
// 	ft_token_add_back(&previous, *var);
// 	ft_token_add_back(var, next);
// 	*top = ft_token_first(*var);
// 	*var = next;
// 	return (0);
// }

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
			if (ft_lexer(&token, line))
				ft_token_clear(&token);
			tmp = token;
			i = 1;
			while (tmp)
			{
				printf("%d\t:\t%s\t:\t%d\n", i++, tmp->content, tmp->type);
				tmp = tmp->next;
			}
			//ft_expend(&token, data.env);
			// tmp = token;
			// ft_expend_var(&token, &tmp, data.env, 0);
			// printf("\n");
			// tmp = token;
			// i = 1;
			// while (tmp)
			// {
			// 	printf("%d\t: %s\n", i++, (char *)tmp->content);
			// 	tmp = tmp->next;
			// }
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
