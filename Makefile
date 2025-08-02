# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhuck <juhuck@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 04:43:07 by jhuck             #+#    #+#              #
#    Updated: 2025/08/02 12:47:36 by juhuck           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol

# ─── Paths ────────────────────────────────────────────────────────────────────
SRC_DIR		= src
FRACT_DIR	= fractals
OBJ_DIR		= obj
INC_DIR		= includes
LIBFT_DIR	= libft
MLX_DIR		= minilibx-linux

# ─── Files ────────────────────────────────────────────────────────────────────
SRC_FILES	= main.c hooks.c events.c render.c utils.c palette.c color.c helpers.c helpers2.c parse.c
FRACT_FILES	= burning_ship.c mandelbrot.c julia.c

SRC_ALL		= $(addprefix $(SRC_DIR)/, $(SRC_FILES)) \
			  $(addprefix $(FRACT_DIR)/, $(FRACT_FILES))

OBJ_ALL		= $(addprefix $(OBJ_DIR)/, $(SRC_ALL:.c=.o))

LIBFT		= $(LIBFT_DIR)/libft.a
MLX_LIB		= $(MLX_DIR)/libmlx.a

# ─── Compilation ──────────────────────────────────────────────────────────────
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -f
MKDIR_P		= mkdir -p
INCLUDES	= -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

ifeq ($(shell uname), Linux)
	LINKS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
else
	LINKS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -lm
endif

# ─── Rules ────────────────────────────────────────────────────────────────────
all: $(NAME)

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJ_ALL)
	@echo "🔗 Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ_ALL) $(LIBFT) $(LINKS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@$(MKDIR_P) $(dir $@)
	@echo "🛠️  Compiling $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT): $(shell find $(LIBFT_DIR)/src -type f -name "*.c")
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)

clean:
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
