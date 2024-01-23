# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 23:20:59 by paubotargue       #+#    #+#              #
#    Updated: 2023/12/28 01:13:19 by pbotargu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c push_swap.c errors.c ini_stack.c libft.c push.c reverse_rotate.c rotate.c sort_five.c sort_three.c split.c stack_utils.c swap.c info_nodes.c 
# Lista de archivos fuente
OBJ = $(SRC:.c=.o)
EXECUTABLE = push_swap

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXECUTABLE)

re: fclean all

.PHONY: all clean fclean re
