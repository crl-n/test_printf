# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnysten <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 14:35:20 by cnysten           #+#    #+#              #
#    Updated: 2022/01/11 14:48:11 by cnysten          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Set your ft_printf path
FT_PRINTF_PATH = ../ft_printf/

NAME = test_printf

SRCS = main.c

OBJS = $(srcs:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME):
	make -C $(FT_PRINTF_PATH)
	gcc $(CFLAGS) -c $(SRCS)
	gcc $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	make -C $(FT_PRINTF_PATH) clean

fclean:
	rm -f $(NAME)
	make -C $(FT_PRINTF_PATH) fclean
