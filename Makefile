# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apoque <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 15:03:55 by apoque            #+#    #+#              #
#    Updated: 2018/03/13 19:02:01 by apoque           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Werror -Wextra -Wall

NAME = libftprintf.a

INC = printf.h

SRC =main.c\
	 ft_printf.c\
	 ft_printf2.c\
	 ft_printf3.c\
	 ft_i.c\
	 ft_li.c\
	 ft_o.c\
	 ft_u.c\
	 ft_x.c\
	 ft_p.c\
	 ft_str.c\
	 ft_char.c\
	 ft_conv_wchar.c\
	 ft_percent.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) libft/*.c libft/Makefile
	make -C libft
	cp libft/libft.a ./$(NAME)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)
	$(CC) $(FLAGS) $(OBJ) -o printf $(NAME)

clean :
	cd libft ; make clean ; cd ..
	rm -rf $(OBJ)

fclean : clean
	cd libft ; make fclean ; cd ..
	rm -rf libftprintf.a

re : fclean all

.PHONY: all clean fclean re
