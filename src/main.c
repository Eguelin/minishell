/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:30:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/24 13:42:29 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_minishell	data;

	(void)argc;
	(void)argv;
	ft_init_minishell(&data, env);
	while (data.env->next)
	{
		printf("%s=%s\n", data.env->name, data.env->content);
		data.env = data.env->next;
	}
	printf("%s=%s\n", data.env->name, data.env->content);
	ft_env_clear(&data.env);
	return (0);
}
