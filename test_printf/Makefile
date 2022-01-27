# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnysten <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 14:35:20 by cnysten           #+#    #+#              #
#    Updated: 2022/01/27 10:57:44 by cnysten          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Set your ft_printf path
FT_PRINTF_PATH = ../../ft_printf

LIB_PATH = $(FT_PRINTF_PATH)/libft

NAME = test_printf

CFLAGS = -Wall -Wextra -Werror -g -I$(FT_PRINTF_PATH)

INCL = -I$(LIB_PATH) -I$(FT_PRINTF_PATH)

FT_SRCS = $(FT_PRINTF_PATH)/ft_printf.c $(FT_PRINTF_PATH)/ptoa.c \
		  $(FT_PRINTF_PATH)/wrapper.c $(FT_PRINTF_PATH)/boolean.c \
		  $(FT_PRINTF_PATH)/setters.c $(FT_PRINTF_PATH)/parser.c \
		  $(FT_PRINTF_PATH)/ftoa.c $(FT_PRINTF_PATH)/itohex.c \
		  $(FT_PRINTF_PATH)/itooctal.c $(FT_PRINTF_PATH)/utoa.c \

FT_OBJS = $(FT_SRCS:%.c=%.o)

FT_PRINTF_A = $(FT_PRINTF_PATH)/libftprintf.a

TEST_SRCS = main.c \
			redirection.c

TEST_OBJS = $(TEST_SRCS:%.c=%.o)

all: $(NAME)

#$(FT_OBJS): $(FT_SRCS)
#	make -C $(FT_PRINTF_PATH)

$(FT_PRINTF_A):
	make -C $(FT_PRINTF_PATH)

$(TEST_OBJS):
	gcc $(CFLAGS) -c $(TEST_SRCS) $(INCL)

$(NAME): $(TEST_OBJS) $(FT_PRINTF_A)
	gcc $(CFLAGS) -o $(NAME) $(TEST_OBJS) $(FT_PRINTF_A) $(INCL)
	#gcc $(CFLAGS) -o $(NAME) $(TEST_OBJS) $(FT_OBJS) $(INCL)

clean:
	rm -f $(TEST_OBJS)
	make -C $(FT_PRINTF_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(FT_PRINTF_PATH) fclean

re: fclean all

