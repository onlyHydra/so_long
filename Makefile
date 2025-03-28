
SRC_DIR = srcs
SRCS = \
	$(SRC_DIR)/validator/check_valid_gameboard.c \
	$(SRC_DIR)/game/mechanics/char_movement.c \
	$(SRC_DIR)/game/visuals/visuals.c \
	$(SRC_DIR)/game/game_loop.c \
	$(SRC_DIR)/initialise/create_board.c \
	$(SRC_DIR)/initialise/initialise.c \
	$(SRC_DIR)/initialise/load_elements.c \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/utils.c \
	$(SRC_DIR)/memory_management/free_mlx.c

# SRCS =	src/main.c src/utils.c src/map_checks.c src/init_utils.c\
# 		src/map_checks_utils.c src/free_utils.c src/initialisation.c\
# 		src/hook_actions.c src/pretty_terminal.c src/move.c

CC = @cc
RM = @rm -f
LIBFT_DIR = imports/ft_printf
GNL_DIR = imports/get_next_line
MLX_DIR = imports/minilibx-linux
CFLAGS =  -g -Wall -Werror -Wextra -Iheader -I$(GNL_DIR) -I$(LIBFT_DIR)/header
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
# here to add libs from gnl
LIBS = $(LIBFT_DIR)/libftprintf.a $(GNL_DIR)/libgnl.a $(MLX_DIR)/libmlx.a
OBJS =	$(SRCS:.c=.o)
NAME = so_long


MLX_PATH = imports/minilibx-linux
# URL to download the MinilibX tarball
MLX_URL = https://cdn.intra.42.fr/document/document/31497/minilibx-linux.tgz

# Path for downloading the tarball
MLX_TAR = imports/minilibx-linux.tgz

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

# # Download and extract MinilibX if not already present
download_mlx:
	@printf "$(WARN_STRING) $(OK_COLOR)Downloading MinilibX...$(NO_COLOR)\n"
	@mkdir -p $(MLX_PATH)
	@curl -L $(MLX_URL) -o $(MLX_TAR)
	@printf "$(WARN_STRING) $(OK_COLOR)Extracting MinilibX...\n $(NO_COLOR)"
	@tar -xvzf $(MLX_TAR) -C imports/ 
	@rm -f $(MLX_TAR)
	@printf "$(OK_STRING)$(OK_COLOR)MinilibX downloaded and extracted.\n $(NO_COLOR)"



%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: check_mlx $(NAME)
$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(GNL_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(LIBS) -o $(NAME)	

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(MLX_DIR)/libmlx.a
	$(MAKE) -C $(GNL_DIR) fclean

re: fclean all
 
.PHONY: all libft clean fcelan re 