# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schiper <schiper@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 12:11:18 by schiper           #+#    #+#              #
#    Updated: 2025/03/17 12:12:14 by schiper          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

IMPORT = imports

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

MLX_PATH = $(IMPORT)/mlx

MLX_LIB = $(MLX_PATH)/libmlx.a

MLX_FLAGS =  -Lmlx -lmlx -framework OpenGL -framework AppKit

LIBFT_PATH = $(IMPORT)/libft

LIBFT_LIB = $(LIBFT_PATH)/libft.a

SRC = srcs

SRC_FILES = 


OBJ = $(SRC_FILES:.c=.o)
