##
## EPITECH PROJECT, 2021
## My Makefile
## File description:
## This file compiles my string lib.
##

LIB_FUNCTIONS = my_fill_string.c \
	my_get_alphanumeric_str.c \
	my_get_str_low_case.c \
	my_get_nbr.c \
	my_get_str_low_case.c \
	my_init_string.c \
	my_insert_at_start.c \
	my_int_to_str.c \
	my_put_nbr.c \
	my_putchar.c \
	my_putstr.c \
	my_replace_char.c \
	my_revstr.c \
	my_show_word_array.c \
	my_str_includes_char.c \
	my_str_is_alpha.c \
	my_str_is_lower_case.c \
	my_str_is_num.c \
	my_str_is_printable.c \
	my_str_is_upper.c \
	my_str_to_word_array.c \
	my_str_capitalize.c \
	my_strcat.c \
	my_strcmp.c \
	my_strcpy.c \
	my_strdup.c \
	my_strlen.c \
	my_strncat.c \
	my_strncmp.c \
	my_strncpy.c \
	my_strstr.c \
	my_str_up_case.c \
	my_throw_error.c \
	my_unsigned_int_to_str.c

OBJ = $(LIB_FUNCTIONS:.c=.o)

NAME = libmy_string.a

all: $(NAME)

$(NAME):
	gcc -c $(LIB_FUNCTIONS)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) -f $(NAME)
	$(RM) -f *.o

re:
	$(MAKE)
	$(MAKE) clean
