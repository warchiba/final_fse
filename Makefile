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
FUNC = main.c draw.c readfile.c get_next_line.c projection.c helptools.c
OBJ = main.o draw.o readfile.o get_next_line.o projection.o helptools.o

all: $(NAME)

$(NAME):
	gcc  -Wall -Wextra -Werror $(FUNC) -L minilibx/ -lmlx -L libft/ -lft -o fdf -framework OpenGL -framework AppKit

clean:
	/bin/rm -Rf $(OBJ)

fclean: clean
	/bin/rm -Rf $(NAME)

re: fclean all

norme:
	norminette $(FUNC) fdf.h