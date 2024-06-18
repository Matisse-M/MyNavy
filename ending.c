/*
** EPITECH PROJECT, 2023
** ending
** File description:
** Conditions to finish MyNavy
*/

#include "game.h"
#include "navy.h"

static int check_nb(game_t *game, int i)
{
    for (int j = 0; j < 8; j++) {
        if (game->map1[i][j] == '2' || game->map1[i][j] == '3' ||
            game->map1[i][j] == '4' || game->map1[i][j] == '5')
            return 1;
    }
    return 0;
}

static int check_x(game_t *game, int i)
{
    int result = 0;

    for (int j = 0; j < 8; j++) {
        if (game->map2[i][j] == 'x')
            result++;
    }
    return result;
}

void check_map(game_t *game)
{
    for (int i = 0; i < 8; i++) {
        if (check_nb(game, i) == 1)
            return;
    }
    game->end = -1;
}

void check_enemy_map(game_t *game)
{
    int x = 0;

    for (int i = 0; i < 8; i++) {
        x += check_x(game, i);
        if (x == 14) {
            game->end = 1;
            return;
        }
    }
}
