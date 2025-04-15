##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Compile and link the program using the lib
##

SRC	=	src/main.c												\
		src/get_file_content.c									\
		src/load_tetriminos/load_single_tetrimino.c 			\
		src/load_tetriminos/tetrimino_error_handling.c 			\
		src/load_tetriminos/load_tetriminos.c 					\
		src/load_tetriminos/format_tetrimino.c 					\
		src/load_tetriminos/format_tetrimino_for_debug.c 		\
		src/load_ui/print_ui.c 									\
		src/tetrimino/print_tetrimino.c 						\
		src/tetrimino/rotate_tetrimino.c						\
		src/tetrimino/spawn_tetrimino.c 						\
		src/tetrimino/move_tetrimino.c 							\
		src/tetrimino/can_spawn_tetrimino.c 					\
		src/tetrimino/check_collision.c							\
		src/tetrimino/set_tetrimino_properties.c 				\
		src/debug_tetris_data.c 								\
		src/game_loop.c 										\
		src/options/parse_options.c 							\
		src/options/help.c 										\
		src/options/option_actions.c 							\
		src/free_tetris.c 										\
		src/is_window_too_small.c 								\
		src/timer.c 											\
		src/destroy_line_if_complete.c 							\
		src/has_loosed_game.c 									\
		src/high_score.c

OBJ = $(SRC:.c=.o)

NAME = tetris

CFLAGS = -Wall -Wextra -Wpedantic -I includes

LFLAGS = 	-lncurses 						\
			-L./lib/my_printf -lmy_printf 	\
			-L./lib/my_string -lmy_string 	\
			-L./lib/my_maths -lmy_maths 	\
			-L./lib/my_array -lmy_array

all:	$(NAME)

$(NAME): $(OBJ)
	$(MAKE) libs
	gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

libs:
	$(MAKE) -C lib/my_string all
	$(MAKE) -C lib/my_maths all
	$(MAKE) -C lib/my_printf all
	$(MAKE) -C lib/my_array all

clean:
	$(RM) -f *~

fclean: clean
	$(RM) -f $(OBJ)
	$(RM) -f $(NAME)

re: fclean all

debug: CFLAGS += -g3
debug: re
