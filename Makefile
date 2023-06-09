# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 14:20:28 by eguelin           #+#    #+#              #
#    Updated: 2023/06/09 14:53:44 by eguelin          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#Standard
BNS_DIR	= bonus/
OUT_DIR	= build/
SRC_DIR	= src/
INC_DIR	= include/
LIB_DIR	= lib/
NAME	= minishell
CC		= cc
CFLAGS	= -Wall -Werror -Wextra $(LIB_INC) -I $(INC_DIR) -g3# -fsanitize=address
RM		= rm -rf
ARC		= ar rcs

#Colors
BLACK	= \033[0;30m
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
PURPLE	= \033[0;35m
CYAN	= \033[0;36m
WHITE	= \033[0;37m

#Sentence
COMP_MSG		= "$(GREEN)Compilation $(NAME) $(WHITE)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(WHITE)"
COMP_BNS_MSG	= "$(GREEN)Compilation of bonus $(NAME) $(WHITE)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(WHITE)"
CLEAN_MSG		= "$(RED)Cleaning $(NAME) $(WHITE)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(WHITE)"
FULL_CLEAN_MSG	= "$(PURPLE)Full cleaning $(NAME) $(WHITE)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(WHITE)"

#Sources
#..._DIR = ../
#..._FILES = ..
#ALL_FILES = $(addprefix $(..._DIR), $(..._FILES))
ALL_FILES		= main.c init.c

LST_DIR			= lst/

ENV_DIR			= env/
ENV_FILES		= ft_env_add_back.c ft_env_add_front.c ft_env_chr.c ft_env_clear.c ft_env_delone.c ft_env_first.c ft_env_last.c ft_env_new.c ft_env_size.c ft_get_env_var.c ft_set_env.c
ALL_FILES		+= $(addprefix $(LST_DIR)$(ENV_DIR), $(ENV_FILES))

PIPE_DIR		= pipe/
PIPE_FILES		= ft_pipe_add_back.c ft_pipe_clear.c ft_pipe_delone.c ft_pipe_last.c ft_pipe_new.c
ALL_FILES		+= $(addprefix $(LST_DIR)$(PIPE_DIR), $(PIPE_FILES))

TOKEN_DIR		= token/
TOKEN_FILES		= ft_token_add_back.c ft_token_add_front.c ft_token_clear.c ft_token_delone.c ft_token_first.c ft_token_last.c ft_token_new.c ft_token_size.c
ALL_FILES		+= $(addprefix $(LST_DIR)$(TOKEN_DIR), $(TOKEN_FILES))

PARS_DIR		= parsing/
PARS_FILES		= ft_parsing.c
ALL_FILES		+= $(addprefix $(PARS_DIR), $(PARS_FILES))

LEXER_DIR		= lexer/
LEXER_FILES		= ft_lexer.c
ALL_FILES		+= $(addprefix $(PARS_DIR)$(LEXER_DIR), $(LEXER_FILES))

TOKEN_P_DIR		= token/
TOKEN_P_FILES	= ft_add_token.c ft_get_token.c ft_token_chevron.c ft_token_dollar.c ft_token_pipe.c ft_token_quote.c ft_token_space.c ft_token_word.c
ALL_FILES		+= $(addprefix $(PARS_DIR)$(LEXER_DIR)$(TOKEN_P_DIR), $(TOKEN_P_FILES))

EXPANDS_DIR		= expands/
EXPANDS_FILES	= ft_expands_classic.c ft_expands_global.c ft_expands_quote.c ft_expands.c
ALL_FILES		+= $(addprefix  $(PARS_DIR)$(LEXER_DIR)$(TOKEN_P_DIR)$(EXPANDS_DIR), $(EXPANDS_FILES))

INC_FILES		= $(NAME).h ft_lst.h s_lst.h ft_minishell.h s_minishell.h ft_parsing.h s_parsing.h

OBJS			= $(addprefix $(OUT_DIR), $(ALL_FILES:.c=.o))
HEADERS			= $(addprefix $(INC_DIR), $(INC_FILES))

#Sources bonus
#..._DIR	= ../
#..._FILES	= ..
#ALL_BNS_FILES	= $(addprefix $(..._DIR), $(..._FILES))
#
#BNS_INC_FILES	= $(NAME)_bonus.h
#
#BNS_OBJS	= $(addprefix $(OUT_DIR), $(ALL_BNS_FILES:.c=.o))
#BNS_HEADERS	= $(addprefix $(INC_DIR), $(BNS_INC_FILES))

#Lib

MYLIB_DIR		= mylib/
MYLIB_FILES		= mylib.a
LIB_FILES		= $(addprefix $(MYLIB_DIR), $(MYLIB_FILES))
LIB_INC			= -I $(addprefix $(LIB_DIR), $(addprefix $(MYLIB_DIR), $(INC_DIR)))

LIB				= $(addprefix $(LIB_DIR), $(LIB_FILES))

#Rules
all: $(NAME)

$(NAME): $(OUT_DIR) $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME) -lreadline
	@echo $(COMP_MSG)
	@norminette | awk '$$NF!="OK!" {print "$(RED)" $$0 "$(WHITE)"}'

$(OUT_DIR)%.o : $(SRC_DIR)%.c Makefile $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OUT_DIR) $(BNS_OBJS) $(LIB)
	$(CC) $(CFLAGS) $(BNS_OBJS) $(LIB) -o $(NAME)_bonus -lreadline
	@echo $(COMP_BNS_MSG)
	@norminette | awk '$$NF!="OK!" {print "$(RED)" $$0 "$(WHITE)"}'

$(OUT_DIR)%.o : $(SRC_DIR)%.c Makefile $(BNS_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -sC ./lib/$(MYLIB_DIR)
	$(RM) $(OUT_DIR)
	@echo $(CLEAN_MSG)

fclean:
	$(MAKE) fclean -sC ./lib/$(MYLIB_DIR)
	$(RM) $(NAME) $(OUT_DIR)
	echo $(CLEAN_MSG)
	echo $(FULL_CLEAN_MSG)

force:

$(LIB): force
	$(MAKE) -sC ./lib/$(MYLIB_DIR)

$(OUT_DIR): force
	mkdir -p $(shell find $(SRC_DIR) -type d | awk -F "$(SRC_DIR)" '$$NF!="$(SRC_DIR)" {print "$(OUT_DIR)"$$(NF)}')

re: fclean all

.PHONY: all bonus clean fclean force re
.SILENT:
