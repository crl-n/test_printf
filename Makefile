# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnysten <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 14:35:20 by cnysten           #+#    #+#              #
#    Updated: 2022/03/31 12:07:49 by cnysten          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Set your ft_printf path
FT_PRINTF_PATH = ../ft_printf

LIB_PATH = $(FT_PRINTF_PATH)/libft

NAME = test_printf

CFLAGS = -Wall -Wextra -Werror -g

INCL = -I$(LIB_PATH) -I$(FT_PRINTF_PATH)

FT_PRINTF_A = $(FT_PRINTF_PATH)/libftprintf.a

SRC = main.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(FT_PRINTF_A):
	make -C $(FT_PRINTF_PATH)

$(OBJ): $(SRC)
	gcc $(CFLAGS) -c $(SRC) $(INCL)

$(NAME): $(OBJ) $(FT_PRINTF_A)
	gcc $(CFLAGS) -o $(NAME) $(OBJ) $(FT_PRINTF_A) $(INCL)

clean:
	-rm -f $(OBJ)
	-rm -f output
	make -C $(FT_PRINTF_PATH) clean

fclean: clean
	-rm -f $(NAME)
	-rm -rf $(NAME).dSYM
	make -C $(FT_PRINTF_PATH) fclean

re: fclean all

