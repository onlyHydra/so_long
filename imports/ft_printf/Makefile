# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schiper <schiper@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 15:45:27 by schiper           #+#    #+#              #
#    Updated: 2025/03/28 16:33:20 by schiper          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Directories
SRC_DIR = src
INC_DIR = header

# Source and Object files
SRC_FILES = $(SRC_DIR)/ft_printf.c $(SRC_DIR)/ft_utils_1.c $(SRC_DIR)/ft_utils_2.c
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)

# Library name
NAME = libftprintf.a

# Default target (build the library)
all: $(NAME)

# Create the library from object files
$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

# Rule to compile .c files into .o files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ_FILES)

# Clean object files and the library
fclean: clean
	rm -f $(NAME)

# Rebuild the library (clean and then make all)
re: fclean all

# Makefile targets
.PHONY: all clean fclean re
