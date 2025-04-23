# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 09:28:31 by mgeorges          #+#    #+#              #
#    Updated: 2025/04/23 09:29:10 by mgeorges         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	

C++		=	c++

C++_FLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp \
			Fixed.cpp
				
OBJS		=	$(SRCS:.cpp=.o)

all: 	$(NAME)

$(NAME): $(OBJS)
		@echo "Compiling $(NAME)...$(C++_FLAGS)"
		@$(C++) $(C++_FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	@$(C++) $(C++_FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all