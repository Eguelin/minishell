/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:36:05 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/28 19:15:46 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "../lib/mylib/include/mylib.h"
# include "lst.h"

typedef struct s_data_token
{
	t_token	**token;
	char	*line;
	size_t	start;
	size_t	end;
	int		type;
}	t_data_token;

////////// [ lexer] //////////
int	ft_lexer(t_token **token, char *line);

////////// [ token ] //////////
int	ft_add_token(t_data_token *data);
int	ft_get_token(t_data_token *data);
int	ft_token_chevron(t_data_token *data);
int	ft_token_dollar(t_data_token *data);
int	ft_token_quote(t_data_token *data);
int	ft_token_pipe(t_data_token *data);
int	ft_token_space(t_data_token *data);
int	ft_token_word(t_data_token *data);

#endif
