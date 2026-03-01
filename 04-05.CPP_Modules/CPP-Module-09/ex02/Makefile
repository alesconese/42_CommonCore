# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/27 18:24:13 by ade-tole          #+#    #+#              #
#    Updated: 2025/03/21 19:15:53 by ade-tole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= PMergeMe

SRCS		= main.cpp PMergeMe.cpp
INC			= PMergeMe.hpp

CC			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 -gdwarf-4 -pedantic #-fsanitize=leak
RM			= rm -f

OBJS		= $(SRCS:.cpp=.o)

%.o:		%.cpp Makefile $(INC) $(TEMPLATES)
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
