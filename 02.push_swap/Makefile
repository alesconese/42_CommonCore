# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-tole <ade-tole@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 15:07:25 by ade-tole          #+#    #+#              #
#    Updated: 2023/12/03 15:15:14 by ade-tole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror -MMD

INCLUDES = push_swap.h

SRCS =  free_error.c ft_push.c ft_rev_rotate.c ft_rotate.c ft_swap.c init_stack.c \
        lst_utils.c push_swap.c sort_nodes.c main.c

OBJS = $(SRCS:.c=.o)

DEPS = $(SRCS:.c=.d)


all: makelibft $(NAME)

%.o:%.c Makefile libft/libft.h libft/libft.a
		$(CC) $(FLAGS) -I ./ -c $< -o $@

$(NAME): $(OBJS)

makelibft:
		$(MAKE) -C libft/

clean:
		$(MAKE) -C libft clean
		rm -rf $(OBJS) $(DEPS)

fclean: clean
		$(MAKE) -C libft/ fclean
		rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
