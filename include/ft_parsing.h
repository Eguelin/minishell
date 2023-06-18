/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:36:05 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/18 14:37:00 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSING_H
# define FT_PARSING_H

////////// [ expands ] //////////
int		ft_expands_quote(t_data_token *data, char *content);
int		ft_expands_global(t_data_token *data);
int		ft_expands_classic(t_data_token *data, char *content);
int		ft_expands(t_data_token *data, t_env *env, char *name, int i);

////////// [ lexer ] //////////
int		ft_fusion_line(t_token *token);
int		ft_lexer(t_token **token, t_env *env, char *line);

////////// [ heredoc ] //////////
int		ft_heredoc_expands(t_token *token, t_env *env, int fd);
int		ft_heredoc_no_expans(t_token *token, int fd);
int		ft_heredoc(t_token *token, t_env *env);
void	ft_replace_heredoc_content(t_token *token, t_token *heredoc);

////////// [ token ] //////////
int		ft_add_token(t_data_token *data);
t_token	**ft_get_ptr_token(t_token **token);
int		ft_get_token(t_data_token *data, t_env *env);
int		ft_token_chevron(t_data_token *data);
int		ft_token_dollar(t_data_token *data, t_env *env, int i);
int		ft_token_quote(t_data_token *data, t_env *env);
int		ft_token_pipe(t_data_token *data);
int		ft_token_space(t_data_token *data);
int		ft_token_word(t_data_token *data);

////////// [ parsing ] //////////
int		ft_parsing(t_minishell *data, char *line);

#endif
