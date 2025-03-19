# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schiper <schiper@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 15:45:27 by schiper           #+#    #+#              #
#    Updated: 2024/12/02 17:53:40 by schiper          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR)

SRC_DIR = src
OBJ_DIR = src
INC_DIR = header

SRC_FILES = $(SRC_DIR)/ft_printf.c $(SRC_DIR)/ft_utils_1.c $(SRC_DIR)/ft_utils_2.c
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME = libftprintf.a

all: $(NAME)


$(NAME): $(OBJ_FILES)
	ar rc $(NAME) $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c  
	$(CC) $(CFLAGS) $(INC_FILES) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re