/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:21:08 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/10 14:29:08 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST_H
# define FT_LST_H

////////// [ env ] //////////
void	ft_env_add_back(t_env **env, t_env *new);
void	ft_env_add_front(t_env **env, t_env *new);

void	ft_env_clear(t_env **env);
void	ft_env_delone(t_env *env);
t_env	*ft_env_first(t_env *env);
t_env	*ft_env_last(t_env *env);
t_env	*ft_env_new(char *name, char *content);
int		ft_env_size(t_env *env);
t_env	*ft_get_env(t_env *env, char *name);
t_env	*ft_pars_env_var(char *env_var);
t_env	*ft_set_env(char **env);
t_env	*ft_env_chr(t_env *env, char *name);

////////// [ pipe ] //////////
void	ft_pipe_add_back(t_pipe **pipe, t_pipe *new);
void	ft_pipe_clear(t_pipe **pipe);
void	ft_pipe_delone(t_pipe *pipe);
t_pipe	*ft_pipe_new(void);
t_pipe	*ft_pipe_last(t_pipe *pipe);

////////// [ token ] //////////
void	ft_token_add_back(t_token **token, t_token *new);
void	ft_token_add_front(t_token **token, t_token *new);
void	ft_token_clear(t_token **token);
void	ft_token_delone(t_token *token);
t_token	*ft_token_first(t_token *token);
t_token	*ft_token_last(t_token *token);
t_token	*ft_token_new(char *content, int type);
int		ft_token_size(t_token *token);

#endif
