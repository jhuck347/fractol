# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhuck <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 04:43:07 by jhuck             #+#    #+#              #
#    Updated: 2024/10/15 04:43:09 by jhuck            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
OS		= $(shell uname)

SRCDIR	= ./src
FRADIR	= ./fractals
INCDIR	= ./includes
OBJDIR	= ./obj

SRC_FILES	= main.c hooks.c events.c render.c utils.c palette.c color.c helpers.c parse.c
FRA_FILES	= fractals/julia.c fractals/mandelbrot.c fractals/burning_ship.c

SRC		= $(addprefix $(SRCDIR)/, $(SRC_FILES))
OBJ		= $(addprefix $(OBJDIR)/, $(SRC_FILES:.c=.o) $(FRA_FILES:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

ifeq ($(OS), Linux)
	MLX		= ./lib/minilibx-linux/
	MLX_LNK	= -L $(MLX) -lmlx -lXext -lX11
	MLX_LIB	= $(MLX)libmlx.a
else
	MLX		= ./lib/minilibx/
	MLX_LNK	= -L $(MLX) -lmlx -framework OpenGL -framework AppKit
	MLX_LIB	= $(MLX)libmlx.a
endif

MLX_INC	= -I $(MLX)

FT		= ./lib/libft/
FT_LIB	= $(FT)libft.a
FT_INC	= -I $(FT)
FT_LNK	= -L $(FT) -lft -lpthread

PRINTF	= ./lib/ft_printf/
PRINTF_LIB = $(PRINTF)libftprintf.a
PRINTF_INC = -I $(PRINTF)
PRINTF_LNK = -L $(PRINTF) -lftprintf

INCLUDES = -I $(INCDIR) $(MLX_INC) $(FT_INC) $(PRINTF_INC)

all: obj $(FT_LIB) $(PRINTF_LIB) $(MLX_LIB) $(NAME)

obj:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)/fractals

$(OBJDIR)/%.o: $(SRCDIR)/%.c includes/constants.h includes/fractol.h
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(OBJDIR)/fractals/%.o: $(FRADIR)/%.c includes/constants.h includes/fractol.h
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(FT_LIB):
	@make -C $(FT)

$(PRINTF_LIB):
	@make -C $(PRINTF)

$(MLX_LIB):
	@make -C $(MLX)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) $(PRINTF_LNK) -lm -o $(NAME)

clean:
	@rm -rf $(OBJDIR)
	@make clean -C $(FT)
	@make clean -C $(PRINTF)
	@make clean -C $(MLX)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(FT)
	@make fclean -C $(PRINTF)

re: fclean all

.PHONY: all obj clean fclean re
