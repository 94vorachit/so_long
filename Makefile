# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/15 17:24:51 by vorhansa          #+#    #+#              #
#    Updated: 2026/04/15 17:43:25 by vorhansa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME_S			:=	$(shell uname -s)
ifeq ($(UNAME_S),Linux)
MLX_DIR			=	minilibx-linux
MLX_NAME		=	libmlx.a
MLX_LINK		=	-L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz -lbsd
MLX_POST		=	@true
EXTRA_OBJS		=	minilibx/mlx_png.o
else
MLX_DIR			=	minilibx
MLX_NAME		=	libmlx.dylib
MLX_LINK		=	./$(MLX_NAME)
MLX_POST		=	mv $(MLX_DIR)/$(MLX_NAME) ./$(MLX_NAME)
EXTRA_OBJS		=
endif

NAME	=	so_long
CC		=	cc
CFLAG	=	-Wall -Wextra -Werror
SRCS	=	src/main.c\
			
OBJS	=	$(SRC:%.c=%.o)

all:		$(NAME)

$(NAME):	make -C $(MLX_DIR)
			$(MLX_POST)
			make bonus -C Libft
			mv Libft/libft.a ./libft.a
			$(GCC) $(CFLAGS) $(OBJS) $(EXTRA_OBJS) libft.a $(MLX_LINK) -o $(NAME)