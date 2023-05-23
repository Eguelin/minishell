/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:36:05 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/23 16:09:29 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../lib/mylib/include/mylib.h"

////////// [ pars_line.c ] //////////
t_dlist	*ft_cut_line(char *line);

////////// [ token.c ] //////////
int		ft_split_token(t_dlist **lst, char *line, size_t *start, size_t *end);
int		ft_dup_token(t_dlist **lst, char *str, size_t start, size_t end);

////////// [ token2.c ] //////////
int		ft_token_chevron(t_dlist **lst, char *str, size_t *start, size_t *end);
int		ft_token_quote(t_dlist **lst, char *str, size_t *start, size_t *end);
int		ft_token_pipe(t_dlist **lst, char *str, size_t *start, size_t *end);
int		ft_token_space(t_dlist **lst, char *str, size_t *start, size_t *end);
int		ft_token_dollar(t_dlist **lst, char *str, size_t *start, size_t *end);

#endif
