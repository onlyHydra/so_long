# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schiper <schiper@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 12:11:18 by schiper           #+#    #+#              #
#    Updated: 2025/03/19 15:32:26 by schiper          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus


CC = gcc

CFLAGS = -Wall -Wextra -Werror -g $(SYSTEM)

OS_NAME = $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	MLXFLAGS =  -Lmlx_Linux -lmlx_Linux -L ./mlx -Imlx_Linux -L ./libft -lft -lXext -lX11 -lm -lz
endif
ifeq ($(UNAME_S), Darwin)
	MLXFLAGS	=	-Lmlx -lmlx -framework OpenGL -framework AppKit
endif

AR			=	ar rcs
RM			=	rm -f
MD			=	mkdir -p
CP			=	cp -f

IMPORT = imports

# Path to the MinilibX folder 
MLX_PATH = $(IMPORT)/minilibx-linux
MLX_LIB = $(MLX_PATH)/libmlx.a

# URL to download the MinilibX tarball
MLX_URL = https://cdn.intra.42.fr/document/document/31497/minilibx-linux.tgz

# Path for downloading the tarball
MLX_TAR = $(IMPORT)/minilibx-linux.tgz

# Paths for libft (if needed for your project)
LIBFT_PATH = $(IMPORT)/libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a

# Path for ft_printf (if needed for your project)
FT_PRINTF_PATH = $(IMPORT)/ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_PATH)/libftprintf.a

#Path for get_next_line (if needed for your project)
GET_NEXT_LINE_PATH = $(IMPORT)/get_next_line
GET_NEXT_LINE_LIB = $(GET_NEXT_LINE_PATH)/libgnl.a


# Sources and object files
SRC_DIR = srcs
MDR_DIR = mandatory
BNS_DIR = bonus
INC_DIR = header
SRC_FILES = 

# Object files
COMMON_OBJ  = $(COMMON_SRC:.c=.o)
MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)
BONUS_OBJ   = $(BONUS_SRC:.c=.o



# Color definitions for terminal output
NO_COLOR      = \033[0m
OK_COLOR      = \033[32;01m
ERROR_COLOR   = \033[31;01m
WARN_COLOR    = \033[33;01m

OK_STRING     = $(OK_COLOR)[OK]$(NO_COLOR)
ERROR_STRING  = $(ERROR_COLOR)[ERROR]$(NO_COLOR)
WARN_STRING   = $(WARN_COLOR)[WARNING]$(NO_COLOR)

# Check if MinilibX is installed
check_mlx:
	@echo "Checking if MinilibX is installed..."
	@if [ ! -d "$(MLX_PATH)" ]; then \
		echo "$(WARN_STRING)$(WARN_COLOR) MinilibX not found, downloading... $(NO_COLOR)"; \
		$(MAKE) download_mlx; \
	else \
	echo  "$(OK_STRING)$(OK_STRING) MinilibX is already installed.$(NO_COLOR)"; \
	fi

# Download and extract MinilibX if not already present
download_mlx:
	@printf "$(WARN_STRING) $(OK_COLOR)Downloading MinilibX...$(NO_COLOR)\n"
	@mkdir -p $(MLX_PATH)
	@curl -L $(MLX_URL) -o $(MLX_TAR)
	@printf "$(WARN_STRING) $(OK_COLOR)Extracting MinilibX...\n $(NO_COLOR)"
	@tar -xvzf $(MLX_TAR) -C $(IMPORT)
	@rm -f $(MLX_TAR)
	@printf "$(OK_STRING)$(OK_COLOR)MinilibX downloaded and extracted.\n $(NO_COLOR)"

all: check_mlx $(NAME)

$(NAME): $(COMMON_OBJ) $(MANDATORY_OBJ)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(COMMON_OBJ) $(MANDATORY_OBJ) -o $(NAME) $(MLXFLAGS)
	@echo "$(OK_STRING) $(OK_COLOR)$(NAME) compiled successfully!$(NO_COLOR)"


# Default target (if no target specified)
.PHONY: all check_mlx download_mlx