##
## EPITECH PROJECT, 2019
## my_printf
## File description:
## makefile
##

NAME	=	libmy.a

SRC	=	src/my_printf.c		\
		src/my_put_nbr.c	\
		src/my_strlen.c		\
		src/my_putchar.c	\
		src/my_putstr.c		\
		src/my_revstr.c		\
		src/my_strcpy.c		\
		src/convert_base.c	\
		src/error_handling.c

OBJ	=	$(SRC:.c=.o)

all	:	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp src/my.h ./include

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
