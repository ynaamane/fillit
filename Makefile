# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynaamane <ynaamane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/11 15:22:52 by ynaamane          #+#    #+#              #
#    Updated: 2019/05/14 19:36:58 by sebbaill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fillit

SRC_DIR := ./src
INC_DIR := ./includes
OBJ_DIR := ./obj
LIB_DIR := ./libft

SRC		:= 	main.c \
			reader.c \
			solvers.c \
			map.c \
			tetriminos.c \
			ft_lstcount.c \
			ft_lstrev.c

OBJ		:=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror

L_FT	:= $(LIB_DIR)
include $(L_FT)/libft.mk

BLUE = \033[36m
UP = \033[A
CUT = \033[K

.PHONY: all clean fclean re

all: lib $(NAME)


lib:
	@$(MAKE) -C libft/ libft.a --no-print-directory
	@echo "\033[32mLibft compiled.\n\033[0m"

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "${BLUE}compiling $(NAME): [$@] ...${END}"
	@$(CC) $(CFLAGS) -o $@ -c $< -I.
	@printf "$(UP)$(CUT)"

$(NAME): lib $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIB_LNK) -o $(NAME)
	@printf "$(UP)$(CUT)"
	@echo "\033[32mFillit compiled.\033[0m"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[31mBinary files deleted.\033[0m"
	@rm -rf $(LIB_DIR)/*.o
	@echo "\033[31mLibft binary files deleted.\033[0m"
	@rm -rf $(LIB_DIR)/*.a
	@echo "\033[31mLibft deleted.\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31mMain executable file deleted.\033[0m"

re: fclean all
