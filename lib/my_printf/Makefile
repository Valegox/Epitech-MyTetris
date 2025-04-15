##
## EPITECH PROJECT, 2021
## My Makefile
## File description:
## This file compiles my printf lib.
##

LIB_FUNCTIONS = my_print_var_functions.c \
	my_printf.c

OBJ = $(LIB_FUNCTIONS:.c=.o)

NAME = libmy_printf.a

CFLAGS = -I ../../includes

all: $(NAME)

$(NAME):
	gcc -c $(LIB_FUNCTIONS) $(CFLAGS)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) -f $(NAME)
	$(RM) -f *.o

re:
	$(MAKE)
	$(MAKE) clean
