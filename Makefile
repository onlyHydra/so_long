NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g


SRCDIR = src
INCDIR = inc
LIBDIR = import
OBJDIR = src


ifeq ($(UNAME_S), Linux)
	LIB_URL = https://cdn.intra.42.fr/document/document/26192/minilibx-linux.tgz
	FLAGS_MINILIBX = -I/usr/include -Imlx_linux -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
else ifeq ($(UNAME_S), Darwin)
	LIB_URL = https://cdn.intra.42.fr/document/document/26193/minilibx_opengl.tgz
	FLAGS_MINILIBX = -framework OpenGL -framework AppKit #-Lmlx
endif



$(MINILIBX_DIR):
    @if [ ! -d $(MINILIBX_DIR) ]; then \
      
	@echo "Downloading MiniLibX for $(UNAME_S) from $(LIB_URL)"
	curl -L -o $(MINILIBX_TGZ_NAME) $(LIB_URL)
	@echo "Download completed."
	@mkdir -p $(MINILIBX_DIR)
	tar -xzf $(MINILIBX_TGZ_NAME) -C $(MINILIBX_DIR) --strip-components 1
	rm -f $(MINILIBX_TGZ_NAME)
    fi
