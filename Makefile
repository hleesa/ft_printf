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

NAME		= libftprintf.a
LIBFTDIR	= ./libft
LIBFTFILE	= libft.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

SRCS = \
	ft_printf.c \
	ft_printf_manda_func_one.c \
	ft_printf_manda_func_two.c \

OBJS_M = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS_M)
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFTFILE) $(NAME)
	$(AR) $@ $?

bonus:

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	make -C $(LIBFTDIR) clean
	$(RM) $(OBJS_M) $(OBJS_B)

fclean: clean
	make -C $(LIBFTDIR) fclean
	$(RM) $(NAME)

re: fclean
	make all

.PHONY: all bonus clean fclean re
