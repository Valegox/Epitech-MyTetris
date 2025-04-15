##
## EPITECH PROJECT, 2021
## My Makefile
## File description:
## This file compiles my array lib.
##

LIB_FUNCTIONS = my_create_array.c \
	my_append_in_array.c \
	my_print_array.c \
	my_get_array_at.c \
	my_get_array_length.c \
	my_set_array_at.c \
	my_insert_in_array.c \
	my_remove_from_array.c \
	my_free_array.c

OBJ = $(LIB_FUNCTIONS:.c=.o)

NAME = libmy_array.a

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
