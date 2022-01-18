# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnysten <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 14:35:20 by cnysten           #+#    #+#              #
#    Updated: 2022/01/18 16:02:32 by cnysten          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Set your ft_printf path
FT_PRINTF_PATH = ../ft_printf

NAME = test_printf

FT_SRCS = $(FT_PRINTF_PATH)/ft_printf.c $(FT_PRINTF_PATH)/ptoa.c

TEST_SRCS = main.c \
	   redirection.c

TEST_OBJS = $(TEST_SRCS:%.c=%.o)

FT_OBJS = $(FT_SRCS:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror -g -I$(FT_PRINTF_PATH)

argp: arg_printer.c
	gcc -o argp arg_printer.c

all: $(NAME)

$(FT_OBJS): $(FT_SRCS)
	make -C $(FT_PRINTF_PATH)

$(NAME): $(FT_OBJS)
	#make -C $(FT_PRINTF_PATH)
	gcc $(CFLAGS) -c $(TEST_SRCS)
	gcc $(CFLAGS) -o $(NAME) $(TEST_OBJS) $(FT_OBJS)

clean:
	rm -f $(TEST_OBJS)
	make -C $(FT_PRINTF_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(FT_PRINTF_PATH) fclean

re: fclean all
