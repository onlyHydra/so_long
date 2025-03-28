# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Source files
SRC = ./get_next_line.c ./get_next_line_utils.c
BONUS_SRC = ./get_next_line_bonus.c ./get_next_line_utils_bonus.c

# Object files
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

# Library name
NAME = libgnl.a

# Default target (build the library)
all: $(NAME)

# Create the library from object files
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for compiling the bonus files
bonus: $(BONUS_OBJ)
	ar rcs $(NAME) $(BONUS_OBJ)

# Clean object files
clean:
	rm -f $(OBJ) $(BONUS_OBJ)

# Clean object files and the library
fclean: clean
	rm -f $(NAME)

# Rebuild the library (clean and then make all)
re: fclean all

# Makefile targets
.PHONY: all clean fclean re bonus
