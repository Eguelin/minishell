/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:25:29 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/19 17:32:58 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_prompt_classic(t_env *env);
static char	*ft_prompt_error(t_env *env);

char	*ft_prompt(t_minishell *data)
{
	free(data->prompt);
	if (g_error)
		data->prompt = ft_prompt_error(data->env);
	else
		data->prompt = ft_prompt_classic(data->env);
	if (!data->prompt)
		ft_error(data, MALLOC_FAILED);
	return (data->prompt);
}

static char	*ft_prompt_classic(t_env *env)
{
	char	*prompt;
	char	*prompt_tab[6];
	t_env	*pwd;

	pwd = ft_get_env(env, "PWD");
	prompt_tab[0] = "(\001\x1B[1;36m\002Minishell \001\x1B[1;34m\002";
	if (!pwd || !pwd->content)
		prompt_tab[1] = "????";
	else
		prompt_tab[1] = pwd->content;
	prompt_tab[2] = "\001\x1B[1;37m\002)$\001\x1B[0m\002 ";
	prompt_tab[3] = NULL;
	prompt = ft_strjoin_tab(prompt_tab);
	if (!prompt)
		return (NULL);
	return (prompt);
}

static char	*ft_prompt_error(t_env *env)
{
	char	*prompt;
	char	*prompt_tab[6];
	t_env	*pwd;

	pwd = ft_get_env(env, "PWD");
	prompt_tab[0] = "\001\x1B[1;37m\002(\001\x1B[1;31m\002";
	prompt_tab[1] = ft_itoa(g_error);
	if (!prompt_tab[1])
		return (NULL);
	prompt_tab[2] = "\001\x1B[1;37m\002)(\001\x1B[1;36m\002Minishell \001\x1B[1;34m\002";
	if (!pwd || !pwd->content)
		prompt_tab[3] = "????";
	else
		prompt_tab[3] = pwd->content;
	prompt_tab[4] = "\001\x1B[1;37m\002)$\001\x1B[0m\002 ";
	prompt_tab[5] = NULL;
	prompt = ft_strjoin_tab(prompt_tab);
	if (!prompt)
		return (free(prompt_tab[1]), NULL);
	free(prompt_tab[1]);
	return (prompt);
}
