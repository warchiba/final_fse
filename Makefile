# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: whorpe <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 23:16:58 by whorpe            #+#    #+#              #
#    Updated: 2019/11/05 23:32:54 by whorpe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I $(IDIR) -I $(LIBFT)/includes/

IDIR = includes/
SDIR = src
ODIR = src
LIBFT = libft

NAME = fillit

DEPS = $(IDIR)/fillit.h

OBJ = $(patsubst %.c,$(ODIR)/%.o,$(_SRC))

SRC = $(patsubst %,$(SDIR)/%,$(_SRC)))

_SRC =	main.c \
		mainsolve.c \
		reader.c \
		solve.c \
		supportfunc.c \
		add_list.c \
		structure.c

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)/libft.a
	gcc $^ $(LIBFT)/libft.a -o $@

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS) -I ./libft/includes/
	@mkdir -p $(dir $@)
	$(CC) -c -o $@ $< $(CFLAGS)

$(LIBFT)/libft.a:
	make -C libft/

clean: cleanlib
	rm -f $(OBJ)

fclean:	clean fcleanlib
	rm -f $(NAME)

re:	fclean all

cleanlib:
	make clean -C libft/

fcleanlib:
	make fclean -C libft/

relib:
	make re -C libft/
