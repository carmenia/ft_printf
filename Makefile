.PHONY: all clean fclean re

NAME = libftprintf.a

INC = printf.h

SRCS = main.c			\
	   ft_printf.c		\
	   ft_sort_options.c\
	   ft_unsigned.c\
	   ft_general_printer.c	\
	   utilities/pf_isdigit.c\
	   utilities/pf_strchr.c\
	   ft_printargs.c\
	   ft_decimal.c\
	   utilities/ft_itoabase.c\

SRCO = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRCO) libft/*.c libft/Makefile
	make -C libft
	cp libft/libft.a ./$(NAME)
	ar -rc $(NAME) $(SRCO)
	ranlib $(NAME)
	$(CC) $(FLAGS) $(SRCO) -o printf $(NAME)

clean :
	cd libft ; make clean ; cd ..
	rm -rf $(SRCO)

fclean : clean
	cd libft : make fclean ; cd ..
	rm -rf $(NAME)

re : fclean all
