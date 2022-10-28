# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: warchiba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/07 21:07:13 by warchiba          #+#    #+#              #
#    Updated: 2019/09/18 13:40:52 by warchiba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLUDE = include/
FUNC = ft_*.c
OBJ = ft_*.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(FUNC) -I./libft.h
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -Rf $(OBJ)

fclean: clean
	/bin/rm -Rf $(NAME)

re: fclean all
