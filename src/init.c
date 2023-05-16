/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:42:57 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/16 16:40:25 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_set_env(t_list	**new_env, char **env);
static void	ft_default_env(t_list	**new_env);
static char	*ft_increase_shell_level(char *shlvl);

void	ft_init_minishell(t_minishell *data, char **env)
{
	data->env = NULL;
	if (env[0])
		ft_set_env(&data->env, env);
	else
		ft_default_env(&data->env);
}

static void	ft_set_env(t_list	**new_env, char **env)
{
	int		i;
	char	*str;
	t_list	*new;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "SHLVL=", 6))
			str = ft_strdup(env[i]);
		else
			str = ft_increase_shell_level(env[i]);
		if (!str)
			exit(1);
		new = ft_lstnew(str);
		if (!new)
		{
			free(str);
			ft_lstclear(new_env, free);
			exit(1);
		}
		ft_lstadd_back(new_env, new);
		i++;
	}
}

static void	ft_default_env(t_list	**new_env)
{
	char cwd[PATH_MAX];
	char *env[3];

	env[0] = ft_strjoin("PWD=", getcwd(cwd, sizeof(cwd)));
	if (!env[0])
		exit(1);
	env[1] = "SHLVL=1";
	env[2] = NULL;
	ft_set_env(new_env, env);
	free(env[0]);
}

static char	*ft_increase_shell_level(char *shlvl)
{
	char	*str;
	char	*str_nb;

	str_nb = ft_itoa(ft_atoi(shlvl + 6) + 1);
	if (!str_nb)
		exit(1);
	str = ft_strjoin("SHLVL=", str_nb);
	free(str_nb);
	if (!str)
		exit(1);
	return (str);
}
