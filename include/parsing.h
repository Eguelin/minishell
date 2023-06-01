/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:36:05 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/01 20:04:15 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../lib/mylib/include/mylib.h"
# include "lst.h"

# define PIPE -1
# define ISOLATOR 0
# define WORD 1
# define IN 3
# define OUT 5
# define APP_END 7
# define HERE_DOC_EX 8
# define HERE_DOC_NO 9

typedef struct s_data_token
{
	t_token	**token;
	char	*line;
	size_t	start;
	size_t	end;
	int		type;
}	t_data_token;

////////// [ expands ] //////////
int	ft_expands_quote(t_data_token *data, char *content);
int	ft_expands_classic(t_data_token *data, char *content);
int	ft_expands(t_data_token *data, t_env *env, char *name, int i);

////////// [ lexer ] //////////
int	ft_fusion_line(t_token **token);
int	ft_lexer(t_token **token, t_env *env, char *line);

////////// [ token ] //////////
int	ft_add_token(t_data_token *data);
int	ft_get_token(t_data_token *data, t_env *env);
int	ft_token_chevron(t_data_token *data);
int	ft_token_dollar(t_data_token *data, t_env *env, int i);
int	ft_token_quote(t_data_token *data, t_env *env);
int	ft_token_pipe(t_data_token *data);
int	ft_token_space(t_data_token *data);
int	ft_token_word(t_data_token *data);

#endif
