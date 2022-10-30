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
SRCS = ./src/*.c
OBJS = ./*.o
HDR = includes/
FLAGS = -Wall -Wextra -Werror

all: $(NAME)
	
$(NAME):
	gcc $(SRCS) $(FLAGS) -I$(HDR) -c 
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean: 
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
