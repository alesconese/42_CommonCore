# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 17:34:45 by ade-tole          #+#    #+#              #
#    Updated: 2025/02/26 17:34:49 by ade-tole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= templates

SRCS		= main.cpp
INC			= Foo.hpp

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
