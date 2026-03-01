# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 18:10:28 by ade-tole          #+#    #+#              #
#    Updated: 2024/11/07 19:21:31 by ade-tole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= intern

SRCS		= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
INC			= Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp \
			RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp

CC			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 -g -pedantic
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
				$(RM) *_shrubbery

re:			fclean $(NAME)

.PHONY: all clean fclean re
