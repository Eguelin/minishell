# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 14:20:28 by eguelin           #+#    #+#              #
#    Updated: 2023/05/23 16:08:40 by eguelin          ###   ########lyon.fr    #
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
CFLAGS	= -Wall -Werror -Wextra -I $(INC_DIR) #-g3 -fsanitize=address
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
ALL_FILES = main.c init.c

LST_DIR = lst/

ENV_DIR = env/
ENV_FILES = ft_env_add_back.c ft_env_add_front.c ft_env_clear.c ft_env_delone.c ft_env_first.c ft_env_last.c ft_env_new.c ft_env_size.c
ALL_FILES += $(addprefix $(LST_DIR)$(ENV_DIR), $(ENV_FILES))

FILE_DIR = file/
FILE_FILES = ft_file_add_back.c ft_file_clear.c ft_file_delone.c ft_file_last.c ft_file_new.c
ALL_FILES += $(addprefix $(LST_DIR)$(FILE_DIR), $(FILE_FILES))

PIPE_DIR = pipe/
PIPE_FILES = ft_pipe_add_back.c ft_pipe_clear.c ft_pipe_delone.c ft_pipe_last.c ft_pipe_new.c
ALL_FILES += $(addprefix $(LST_DIR)$(PIPE_DIR), $(PIPE_FILES))

PARS_DIR = parsing/
PARS_FILES = pars_line.c ft_token.c ft_token2.c
ALL_FILES += $(addprefix $(PARS_DIR), $(PARS_FILES))

INC_FILES	= $(NAME).h lst.h parsing.h

OBJS		= $(addprefix $(OUT_DIR), $(ALL_FILES:.c=.o))
HEADERS		= $(addprefix $(INC_DIR), $(INC_FILES))

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
MYLIB_DIR	= mylib/
MYLIB_FILES	= mylib.a
LIB_FILES	= $(addprefix $(MYLIB_DIR), $(MYLIB_FILES))

LIB			= $(addprefix $(LIB_DIR), $(LIB_FILES))

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
	$(MAKE) clean -C ./lib/$(MYLIB_DIR)
	$(RM) $(OUT_DIR)
	@echo $(CLEAN_MSG)

fclean:
	$(MAKE) fclean -C ./lib/$(MYLIB_DIR)
	$(RM) $(NAME) $(OUT_DIR)
	echo $(CLEAN_MSG)
	echo $(FULL_CLEAN_MSG)

force:

$(LIB): force
	$(MAKE) -C ./lib/$(MYLIB_DIR)

$(OUT_DIR): force
	mkdir -p $(shell find $(SRC_DIR) -type d | awk -F "$(SRC_DIR)" '$$NF!="$(SRC_DIR)" {print "$(OUT_DIR)"$$(NF)}')

re: fclean all

.PHONY: all bonus clean fclean force re
.SILENT:
