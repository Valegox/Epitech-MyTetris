/*
** EPITECH PROJECT, 2021
** Tetris bootstrap
** File description:
** Debug Tetris data if using -D
*/

#include <stdlib.h>
#include "my_string.h"
#include "my_printf.h"
#include "my_tetris.h"

char *get_key_from_code(int code)
{
    char *key = NULL;

    if (code == 260)
        return "KEY_LEFT";
    if (code == 261)
        return "KEY_RIGHT";
    if (code == 259)
        return "KEY_UP";
    if (code == 258)
        return "KEY_DOWN";
    key = my_init_string(1);
    key[0] = code;
    return key;
}

void debug_keys(game_keys_t *k)
{
    char *codes[] = { get_key_from_code(k->left),
        get_key_from_code(k->right),
        get_key_from_code(k->turn),
        get_key_from_code(k->drop),
        get_key_from_code(k->quit),
        get_key_from_code(k->pause),
        NULL
    };

    my_printf("Key left: %s (%i)\n", codes[0], k->left);
    my_printf("Key right: %s (%i)\n", codes[1], k->right);
    my_printf("Key turn: %s (%i)\n", codes[2], k->turn);
    my_printf("Key drop: %s (%i)\n", codes[3], k->drop);
    my_printf("Key quit: %s (%i)\n", codes[4], k->quit);
    my_printf("Key pause: %s (%i)\n", codes[5], k->pause);
    for (int i = 0; codes[i] != NULL; i++) {
        if (my_strlen(codes[i]) == 1) {
            free(codes[i]);
        }
    }
}

void debug_tetris_data(tetris_t *tetris)
{
    debug_keys(tetris->keys);
    if (tetris->with_next) {
        my_printf("Next: Yes\n");
    } else {
        my_printf("Next: No\n");
    }
    my_printf("Level: %i\n", tetris->level);
    my_printf("Size: %i*%i\n", tetris->map->height, tetris->map->width);
    my_printf("\n");
}
