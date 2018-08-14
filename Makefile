.PHONY: all clean fclean re

NAME = libftprintf.a

INC = printf.h

SRCS = main.c			\
	   ft_printf.c		\
	   arg_handler_format.c\
	   arg_handler_options.c\
	   dint.c				\
	   print_percent.c


SRCO = $(SRCS: .c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRCO) libft/*.c libft/Makefile
	make -C libft
	cp libft/libft.a ./$(NAME)
	ar -rc $(NAME) 4(SRCO)
	ranlib $(NAME)
	$(CC) $(FLAGS) $(SRCO) -o printf $(NAME)

clean :
	cd libft ; make clean ; cd ..
	rm -rf $(SRCO)

fclean : clean
	cd libft : make fclean ; cd ..
	rm -rf $(NAME)

re : fclean all
