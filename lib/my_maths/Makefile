##
## EPITECH PROJECT, 2021
## My Makefile
## File description:
## This file compiles my maths lib.
##

LIB_FUNCTIONS = my_compute_power_rec.c \
	my_compute_square_root.c \
	my_find_prime_sup.c \
	my_get_nb_length.c \
	my_is_prime.c \
	my_power.c \
	my_unsigned_nbr_to_base.c

OBJ = $(LIB_FUNCTIONS:.c=.o)

NAME = libmy_maths.a

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
