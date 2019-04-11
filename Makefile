# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynaamane <ynaamane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/11 15:22:52 by ynaamane          #+#    #+#              #
#    Updated: 2019/04/11 16:18:44 by ynaamane         ###   ########.fr        #
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
			solver.c \
			map.c \
			tetrimino.c
OBJ		:=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

# compiler and flags
CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror -peantic
OFLAGS	:=	-pipe -flto
CFLAGS	+=	$(OFLAGS)

# libraries
L_FT	:= $(LIB_DIR)/libft

.PHONY: all clean fclean re

all:
		mkdir-p $(OBJ_DIR)
		@$(MAKE) -C $(L_FT) --no-print-directory
		@$(MAKE) $(NAME) --no-print-directory

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(LIB_INC)
