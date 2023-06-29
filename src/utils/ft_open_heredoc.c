/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:33:26 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/29 17:43:01 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_name_heredoc(void);

int	ft_open_heredoc(t_token *heredoc, int *fd_tmp)
{
	char	*name;

	name = ft_name_heredoc();
	if (!name)
		return (MALLOC_FAILED);
	free(heredoc->content);
	heredoc->content = name;
	*fd_tmp = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (*fd_tmp == -1)
		return (ft_printf_error("%s: Error opening temporary file\n", \
		ft_get_data(NULL)->name), free(name), OPEN_FAILED);
	return (0);
}

static char	*ft_name_heredoc(void)
{
	struct stat	path_stat;
	char		*name;
	char		*nbr;
	int			i;

	i = 0;
	while (1)
	{
		nbr = ft_itoa(i);
		if (!nbr)
			return (NULL);
		name = ft_strjoin("/var/tmp/herdoc", nbr);
		if (!name)
			return (free(nbr), NULL);
		free(nbr);
		if (!stat(name, &path_stat))
		{
			i++;
			free(name);
		}
		else
			break ;
	}
	return (name);
}
