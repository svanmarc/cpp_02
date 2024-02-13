# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svanmarc <@student.42perpignan.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 09:06:31 by svanmarc          #+#    #+#              #
#    Updated: 2024/02/13 09:08:31 by svanmarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = BSP

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -Wno-unused-function

SRC = main.cpp Fixed.cpp Point.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re