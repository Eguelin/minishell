/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:21:08 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/16 08:27:23 by eguelin          ###   ########lyon.fr   */
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
char	**ft_env_to_tab(t_env *env);
t_env	*ft_get_env(t_env *env, char *name);
t_env	*ft_pars_env_var(char *env_var);
t_env	*ft_set_env(char **env);
t_env	*ft_env_chr(t_env *env, char *name);

////////// [ lcmd ] //////////
void	ft_lcmd_add_back(t_lcmd **lcmd, t_lcmd *new);
void	ft_lcmd_clear(t_lcmd **lcmd);
void	ft_lcmd_delone(t_lcmd *lcmd);
t_lcmd	*ft_lcmd_new(void);
t_lcmd	*ft_lcmd_last(t_lcmd *lcmd);

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
