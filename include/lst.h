/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:21:08 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/23 14:50:25 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

typedef struct s_env
{
	char			*name;
	char			*content;
	struct s_env	*previous;
	struct s_env	*next;
}	t_env;

typedef struct s_file
{
	char			*name;
	int				type;
	struct s_file	*next;
}	t_file;

typedef struct s_pipe
{
	char			**cmd;
	t_file			*in;
	t_file			*out;
	struct s_pipe	*next;
}	t_pipe;

////////// [ env ] //////////
void	ft_env_add_back(t_env **env, t_env *new);
void	ft_env_add_front(t_env **env, t_env *new);
void	ft_env_clear(t_env **env, void (*del)(void*));
void	ft_env_delone(t_env *env, void (*del)(void*));
t_env	*ft_env_first(t_env *env);
t_env	*ft_env_last(t_env *env);
t_env	*ft_env_new(char *name, char *content);
int		ft_env_size(t_env *env);

////////// [ file ] //////////
t_file	*ft_file_new(char *name, int type);
void	ft_file_add_back(t_file **file, t_file *new);
t_file	*ft_file_last(t_file *file);
void	ft_file_clear(t_file **file, void (*del)(void*));
void	ft_file_delone(t_file *file, void (*del)(void*));

////////// [ pipe ] //////////
t_pipe	*ft_pipe_new(void);
void	ft_pipe_add_back(t_pipe **pipe, t_pipe *new);
t_pipe	*ft_pipe_last(t_pipe *pipe);
void	ft_pipe_clear(t_pipe **pipe, void (*del)(void*));
void	ft_pipe_delone(t_pipe *pipe, void (*del)(void*));

#endif
