# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-tole <ade-tole@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 21:49:55 by ade-tole          #+#    #+#              #
#    Updated: 2023/12/17 21:49:57 by ade-tole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

FLAGS = -Wall -Wextra -Werror -MMD

MLX = -lmlx -Lmlx -framework OpenGL -framework AppKit

SRC =  fractol.c render.c mandelbrot.c julia.c burningship.c events.c

OBJ = $(SRC:.c=.o)

DEPS = $(SRC:.c=.d)

all: makelib $(NAME)

$(NAME): $(OBJ)
		$(CC) $(FLAGS) libft/libft.a mlx/libmlx.a $(MLX) $(OBJ) -o $(NAME)

%.o:%.c Makefile libft/libft.a mlx/libmlx.a
		$(CC) $(FLAGS) -Imlx -c $< -o $@

makelib:
		$(MAKE) -C libft/
		$(MAKE) -C mlx/

clean:
		$(MAKE) -C libft fclean
		$(MAKE) -C mlx clean
		rm -rf $(OBJ) $(DEPS)

fclean: clean
		rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re makelibft