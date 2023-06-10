/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:37:13 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/10 14:21:21 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_pars_name(char *env_var, char **name);
static int	ft_pars_content(char *env_var, char **content);

t_env	*ft_pars_env_var(char *env_var)
{
	t_env	*new;
	char	*name;
	char	*content;

	if (ft_pars_name(env_var, &name))
		return (NULL);
	if (ft_pars_content(env_var, &content))
		return (free(name), NULL);
	new = ft_env_new(name, content);
	if (!new)
		return (free(name), free(content), NULL);
	return (new);
}

static int	ft_pars_name(char *env_var, char **name)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = start;
	while (env_var[end] && env_var[end] != '=')
		end++;
	*name = ft_substr(env_var, start, end);
	if (!*name)
		return (1);
	return (0);
}

static int	ft_pars_content(char *env_var, char **content)
{
	char	*str;

	str = ft_strchr(env_var, '=');
	if (str)
	{
		*content = ft_strdup(str + 1);
		if (!*content)
			return (1);
	}
	else
		*content = NULL;
	return (0);
}
