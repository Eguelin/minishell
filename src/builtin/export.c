/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:05:31 by naterrie          #+#    #+#             */
/*   Updated: 2023/05/31 15:43:24 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"

// int	ft_export(t_env *env, char **cmd)
// {
// 	t_list	*new;
// 	char	*str;
// 	int		i;

// 	if (cmd[1])
// 	{
// 		str = ft_strdup(cmd[1]);
// 		if (!str)
// 			return (1);
// 		new = ft_lstnew(str);
// 		ft_lstadd_back(env, new);
// 	}
// 	i = 1;
// 	while (i <= 177)
// 	{
// 		i++;
// 	}
// 	return (0);
// }

// Check si la variable existe deja
// Indexage par croissance selon la table ascii
// Plusieurs export peuvent etre fait en une commande
