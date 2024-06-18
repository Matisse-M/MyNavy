/*
** EPITECH PROJECT, 2023
** display
** File description:
** MyNavy
*/

#include <signal.h>
#include "game.h"
#include "navy.h"

void update_enemy_map(game_t *game, int val, char *line)
{
    mini_printf("\nresult: %s:", case_hit(line));
    if (enemy_pid[3] == 1) {
        mini_printf("hit\n");
        game->map2[(val - 1) % 8][(val - 1) / 8] = 'x';
    } else {
        mini_printf("missed\n");
        game->map2[(val - 1) % 8][(val - 1) / 8] = 'o';
    }
}

void update_hit(int hit, char *pos)
{
    mini_printf("\nresult: %s:", pos);
    if (hit > 0) {
        mini_printf("hit\n");
        kill(enemy_pid[0], SIGUSR1);
    } else {
        mini_printf("missed\n");
        kill(enemy_pid[0], SIGUSR2);
    }
}
