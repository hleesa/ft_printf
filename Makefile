# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salee2 <salee2n@student.42seoul.k>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 12:29:43 by salee2            #+#    #+#              #
#    Updated: 2022/07/15 15:43:06 by salee2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = \
	ft_printf.c \
	ft_printf_manda_func_one.c \
	ft_printf_manda_func_two.c \

OBJS_M = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS_M)
	ar rcs $@ $?

bonus: $(OBJS_B)
	make OBJS_M="$(OBJS_B)"

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS_M) $(OBJS_B)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

.PHONY: all bonus clean fclean re
