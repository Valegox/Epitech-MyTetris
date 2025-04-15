/*
** EPITECH PROJECT, 2021
** Tetris
** File description:
** Parse tetris options
*/

#include <unistd.h>
#include <getopt.h>
#include "my_printf.h"
#include "my_tetris.h"

static const struct option long_opts[] = {
    { "help", no_argument, 0, 'h' },
    { "level", required_argument, 0, 'L' },
    { "key-left", required_argument, 0, 'l' },
    { "key-right", required_argument, 0, 'r' },
    { "key-turn", required_argument, 0, 't' },
    { "key-drop", required_argument, 0, 'd' },
    { "key-quit", required_argument, 0, 'q' },
    { "key-pause", required_argument, 0, 'p' },
    { "map-size", required_argument, 0, 'm' },
    { "without-next", no_argument, 0, 'w' },
    { "debug", no_argument, 0, 'D' },
    { 0, 0, 0, 0 }
};

static const option_action_t opts_actions[] = {
    { 'L', &set_level },
    { 'l', &set_key },
    { 'r', &set_key },
    { 't', &set_key },
    { 'd', &set_key },
    { 'q', &set_key },
    { 'p', &set_key },
    { 'm', &set_map_size },
    { 'w', &set_next },
    { 'D', &set_debug },
    { '\0', NULL }
};

int handle_option_actions(char opt, char *binary_name, tetris_t *tetris)
{
    if (opt == 'h') {
        print_help(binary_name);
        return 0;
    }
    for (int i = 0; opts_actions[i].option != '\0'; i++) {
        if (opts_actions[i].option == opt) {
            return opts_actions[i].action(opts_actions[i].option, optarg,
            tetris);
        }
    }
    return 84;
}

tetris_t *parse_options(int ac, char **av, tetris_t *tetris)
{
    int opt = 0;
    int opt_index = 0;

    opt = getopt_long(ac, av, "hL:l:r:t:d:q:p:m:wD", long_opts, &opt_index);
    while (opt != -1) {
        if (handle_option_actions(opt, av[0], tetris) == 84) {
            return NULL;
        }
        opt = getopt_long(ac, av, "hL:l:r:t:d:q:p:m:wD", long_opts,
        &opt_index);
    }
    return tetris;
}
