# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/15 17:24:51 by vorhansa          #+#    #+#              #
#    Updated: 2026/04/16 02:34:03 by vorhansa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME_S			:=	$(shell uname -s)
ifeq ($(UNAME_S),Linux)
MLX = minilibx-linux
MLX_LIB = $(MLX)/libmlx.a
FLAGS = -lXext -lX11 ./$(MLX)/libmlx.a -I./$(MLX) -L./$(MLX) -lmlx
else
MLX = minilibx-mac
FLAGS = -framework OpenGL -framework AppKit -I./$(MLX) -L./$(MLX) -lmlx
endif

HEADER	=	inc/so_long.h
NAME	=	so_long
CC		=	cc
CFLAG	=	-Wall -Wextra -Werror
RM		=	rm -rf
SRCS	=	src/main.c\
			src/ft_characters.c\
			src/ft_exit.c\
			src/ft_movements.c\
			src/ft_utils.c\
			src/ft_validate.c\
			src/get_next_line.c
			
OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)
				
$(NAME):	$(OBJS)
			make -C $(MLX)
			make -C libft
			mv libft/libft.a ./libft.a
			$(CC) $(CFLAG) -o $@ $(OBJS) $(MLX_LIB) $(FLAGS) libft.a

%.o: %.c
	$(CC) $(CFLAG) -I. -Iinc -Ilibft -I$(MLX) -c $< -o $@
				
clean:
				$(RM) $(OBJS)
				make clean -C $(MLX)
				make clean -C libft

fclean:			clean
				$(RM) $(NAME) libft.a

re:				fclean all

.PHONY:		all clean fclean re