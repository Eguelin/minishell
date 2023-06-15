/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_parsing.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:36:05 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/14 14:40:07 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_PARSING_H
# define S_PARSING_H

# define PIPE -1
# define ISOLATOR 0
# define WORD 1
# define IN 3
# define OUT 6
# define APP_END 9
# define HERE_DOC_EX 12
# define HERE_DOC_NO 13

typedef struct s_data_token
{
	t_token	**token;
	char	*line;
	size_t	start;
	size_t	end;
	int		type;
}	t_data_token;

#endif
