# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-tole <ade-tole@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 13:19:17 by ade-tole          #+#    #+#              #
#    Updated: 2023/12/14 13:20:21 by ade-tole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S = server
NAME_C = client

CC = gcc

FLAGS = -Wall -Wextra -Werror -MMD

SRC_S =  server.c
SRC_C = client.c

OBJ_S = $(SRC_S:.c=.o)
OBJ_C = $(SRC_C:.c=.o)

DEPS = $(SRC_S:.c=.d) $(SRC_C:.c=.d)


all: makelibft $(NAME_S) $(NAME_C)

$(NAME_S): $(OBJ_S)
		$(CC) $(FLAGS) libft/libft.a -o $(NAME_S) $(OBJ_S)
$(NAME_C): $(OBJ_C)
		$(CC) $(FLAGS) libft/libft.a -o $(NAME_C) $(OBJ_C)

%.o:%.c Makefile libft/libft.h libft/libft.a
		$(CC) $(FLAGS) -c $< -o $@

makelibft:
		$(MAKE) -C libft/

clean:
		$(MAKE) -C libft clean
		rm -rf $(OBJ_S) $(OBJ_C) $(DEPS)

fclean: clean
		$(MAKE) -C libft/ fclean
		rm -f $(NAME_S) $(NAME_C)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re makelibft