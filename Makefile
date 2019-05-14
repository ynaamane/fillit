# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynaamane <ynaamane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/11 15:22:52 by ynaamane          #+#    #+#              #
#    Updated: 2019/05/14 17:58:13 by sebbaill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fillit

# directories
SRC_DIR := ./src
INC_DIR := ./includes
OBJ_DIR := ./obj
LIB_DIR := ./libft

# src / obj files
SRC		:= 	main.c \
			reader.c \
			solvers.c \
			map.c \
			tetriminos.c \
			ft_lstcount.c \
			ft_lstrev.c
OBJ		:=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

# compiler and flags
CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror

# libraries
L_FT	:= $(LIB_DIR)
include $(L_FT)/libft.mk

BLUE = \033[36m
UP = \033[A
CUT = \033[K

.PHONY: all clean fclean re

all: lib $(NAME)


lib:
	@$(MAKE) -C libft/ libft.a --no-print-directory
#	@echo "\n"
#	@$(MAKE) $(NAME) --no-print-directory

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
#	$(CC) $(CFLAGS) $(LIB_INC) -I $(INC_DIR) -o $@ -c $<
#	@echo "\033[32mAdd $@ to $(OBJ_DIR)\033[0m"
	@echo "${BLUE}compiling [$@] ...${END}"
	@$(CC) $(CFLAGS) -o $@ -c $< -I.
	@printf "$(UP)$(CUT)"

$(NAME): lib $(OBJ)
	$(CC) $(OFLAGS) $(OBJ) $(LIB_LNK) -o $(NAME)
	@echo "\033[32mCompiled 'fillit'.\033[0m"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[31mBinary files deleted.\033[0m"
	@rm -rf $(LIB_DIR)/*.o
	@echo "\033[31mLibft binary files deleted.\033[0m"
	@rm -rf $(LIB_DIR)/*.a
	@echo "\033[31mLibft.a as been deleted.\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31mMain executable file deleted.\033[0m"

re: fclean all
#	@$(MAKE) fclean --no-print-directory
#	@$(MAKE) all --no-print-directory

