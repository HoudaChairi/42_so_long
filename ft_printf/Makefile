# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/05 11:44:05 by hchairi           #+#    #+#              #
#    Updated: 2023/03/20 12:48:59 by hchairi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ./ft_printf.c \
	./ft_putstr.c \
	./ft_putnbr.c \
	./ft_putchar.c \
	./ft_hexanbr.c \
	./ft_cas.c \

CC = cc 

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@ar -rc $(NAME) $(OBJ)

%.o : %.c
	@$(CC) $(CFLAGS) -c $<

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f libftprintf.a

re : fclean all

.PHONY : all clean fclean re
