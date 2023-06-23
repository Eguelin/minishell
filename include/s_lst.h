/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_lst.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:21:08 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/14 09:42:37 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_LST_H
# define S_LST_H

typedef struct s_env
{
	char			*name;
	char			*content;
	struct s_env	*previous;
	struct s_env	*next;
}	t_env;

typedef struct s_token
{
	char			*content;
	int				type;
	struct s_token	*previous;
	struct s_token	*next;
}	t_token;

typedef struct s_lcmd
{
	char			**cmd;
	t_token			*file;
	struct s_lcmd	*next;
}	t_lcmd;

#endif
