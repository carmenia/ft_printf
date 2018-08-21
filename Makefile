# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apoque <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 15:03:55 by apoque            #+#    #+#              #
#    Updated: 2018/08/21 16:13:12 by carmenia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Werror -Wextra -Wall

NAME = libftprintf.a

INC = ft_printf.h

SRC =main.c\
	 ft_printf.c\
	 ft_i.c\
	 ft_li.c\
	 ft_o.c\
	 ft_u.c\
	 ft_x.c\
	 ft_p.c\
	 ft_str.c\
	 ft_char.c\
	 ft_conv_wchar.c\
	 ft_text_parser.c\
	 ft_treatement.c\
	 ft_print_chars.c\
	 ft_options.c\
	 ft_option_utilities.c\
	 

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
