# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 10:08:42 by ncharbog          #+#    #+#              #
#    Updated: 2024/11/21 09:43:50 by ncharbog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

SRC = handle_input.c \
	handle_input2.c \
	big_list.c \
	combinations.c \
	exec_operations.c \
	exec_operations2.c \
	exec_operations_utils.c \
	exec_print.c \
	exec_print2.c \
	exec_print3.c \
	find_case.c \
	operations.c \
	small_list.c \
	sort_utils.c \
	sort_utils2.c \
	stacks_utils.c \
	stacks_utils2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re:	fclean all

.PHONY: all clean fclean re bonus
