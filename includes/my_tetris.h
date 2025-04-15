/*
** EPITECH PROJECT, 2021
** Tetris bootstrap
** File description:
** Tetris bootstrap header file
*/

#ifndef MY_TETRIS
    #define MY_TETRIS

    #include "my_array.h"
    #include "time.h"

    #define SUCCESS_STATUS (0)
    #define ERROR_STATUS (84)

    #define MAP_X (28)

    typedef struct tetrimino_s {
        char *name;
        int width;
        int height;
        int color;
        char *content;
    } tetrimino_t;

    typedef struct playing_tetrimino_s {
        tetrimino_t *tetrimino;
        int x;
        int y;
        int next_type;
    } playing_tetrimino_t;

    typedef struct game_keys_s {
        int left;
        int right;
        int turn;
        int drop;
        int quit;
        int pause;
    } game_keys_t;

    typedef struct map_s {
        int width;
        int height;
    } map_t;

    typedef struct tetris {
        playing_tetrimino_t *playing_tmino;
        my_array_t tetriminos;
        map_t *map;
        game_keys_t *keys;
        int level;
        int with_next;
        int debug_mode;
        int destroyed_lines;
        int lines_counter;
        int score;
        int high_score;
    } tetris_t;

    typedef struct option_action_s {
        char option;
        int (*action)(char opt, char *param, tetris_t *tetris);
    } option_action_t;

    my_array_t load_tetriminos(int debug_mode, map_t *map);
    tetrimino_t *load_single_tetrimino(char *name, map_t *map);
    char *get_file_content(char *path_name);
    tetrimino_t *set_tetrimino_properties(char *name, char *content,
    char **properties);

    int str_ends_with(char *str, char *value);
    int are_properties_valid(char **properties);
    int is_size_valid(tetrimino_t *tmino, map_t *map);
    int are_tmino_characters_valid(char *content);

    playing_tetrimino_t *spawn_tetrimino(my_array_t tetriminos,
    playing_tetrimino_t *prev);
    int print_tetrimino(tetrimino_t *tetrimino, int x, int y);
    int erase_tetrimino(tetrimino_t *tetrimino, int x, int y);
    int print_playing_tetrimino(playing_tetrimino_t *tetrimino);
    int erase_playing_tetrimino(playing_tetrimino_t *tetrimino);
    char *format_tmino(char *prev_content, int width, int height);
    int move_tetriminos(playing_tetrimino_t *tmino, int ch, game_keys_t *keys);
    int drop_tetrimino(playing_tetrimino_t *tmino);
    int handle_gravity(playing_tetrimino_t *tmino, int level, clock_t *time);
    int call_new_tetriminos(tetris_t *tetris);
    void print_tmino_for_debug(tetrimino_t *tmino);
    void rotate_tetrimino_right(playing_tetrimino_t *playing_tmino,
    map_t *map);
    char get_tetrimino_at(tetrimino_t *tetrimino, int pos_x, int pos_y);
    int can_spawn_tetrimino(tetris_t *tetris);
    int check_collision(playing_tetrimino_t *tmino);

    tetris_t *parse_options(int ac, char **av, tetris_t *tetris);
    void debug_tetris_data(tetris_t *tetris);

    int game_loop(tetris_t *tetris);
    int print_ui(int map_width, int map_height);

    void print_help(char *binary_name);
    int set_level(__attribute__((unused)) char opt, char *param,
    tetris_t *tetris);
    int set_key(char opt, char *param, tetris_t *tetris);
    int set_map_size(__attribute__((unused)) char opt, char *param,
    tetris_t *tetris);
    int set_next(__attribute__((unused)) char opt, char *param,
    tetris_t *tetris);
    int set_debug(__attribute__((unused)) char opt, char *param,
    tetris_t *tetris);

    void free_tetris(tetris_t *tetris);
    int is_window_too_small(map_t *map);
    void print_timer(clock_t time);
    void destroy_complete_lines(tetris_t *tetris);
    int has_loosed_game(map_t *map);

    int get_high_score(void);
    void display_high_score(tetris_t *tetris);
    void save_score_if_higher(tetris_t *tetris);

#endif
