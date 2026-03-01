# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/17 19:31:39 by ade-tole          #+#    #+#              #
#    Updated: 2024/08/17 19:31:42 by ade-tole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= bank

SRCS		= tests.cpp Account.cpp
INC			= Account.hpp

CC			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 -g -pedantic -fsanitize=leak
RM			= rm -f

OBJS		= $(SRCS:.cpp=.o)

%.o:		%.cpp Makefile $(INC)
				@$(CC) $(CPPFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
				$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY: all clean fclean re
