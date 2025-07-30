# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 04:43:07 by jhuck             #+#    #+#              #
#    Updated: 2025/07/30 10:01:10 by marvin           ###   ########.fr        #
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
SRC_FILES	= main.c hooks.c events.c render.c utils.c palette.c color.c helpers.c parse.c
FRACT_FILES	= burning_ship.c mandelbrot.c julia.c

SRCS		= $(addprefix $(SRC_DIR)/, $(SRC_FILES)) \
			  $(addprefix $(FRACT_DIR)/, $(FRACT_FILES))

OBJS		= $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

LIBFT		= $(LIBFT_DIR)/libft.a
MLX_LIB		= $(MLX_DIR)/libmlx.a

# ─── Compilation ──────────────────────────────────────────────────────────────
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -f
INCLUDES	= -I$(INC_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(MLX_DIR)

ifeq ($(shell uname), Linux)
	LINKS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
else
	LINKS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -lm
endif

# ─── Rules ────────────────────────────────────────────────────────────────────
all: $(NAME)

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT)  $(LINKS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX_LIB):
	@make -C $(MLX_DIR)

clean:
	$(RM) -r $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
