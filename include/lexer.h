/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:36:05 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/26 15:19:35 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "../lib/mylib/include/mylib.h"

////////// [ lexer] //////////
int	ft_lexer(t_dlist **dlst, char *line);

////////// [ token ] //////////
int	ft_add_token(t_dlist **dlst, char *str, size_t start, size_t size);
int	ft_get_token(t_dlist **lst, char *str, size_t *start, size_t *end);
int	ft_token_chevron(t_dlist **lst, char *str, size_t *start, size_t *end);
int	ft_token_dollar(t_dlist **lst, char *str, size_t *start, size_t *end);
int	ft_token_quote(t_dlist **lst, char *str, size_t *start, size_t *end);
int	ft_token_pipe(t_dlist **lst, char *str, size_t *start, size_t *end);
int	ft_token_space(t_dlist **lst, char *str, size_t *start, size_t *end);
int	ft_token_word(t_dlist **dlst, char *str, size_t *start, size_t *end);

#endif
