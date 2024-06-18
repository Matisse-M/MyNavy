/*
** EPITECH PROJECT, 2023
** hub
** File description:
** Several function for MyNavy
*/

#include <stdlib.h>
#include "navy.h"
#include "game.h"

int usage(char *name)
{
    mini_printf("USAGE\n     %s [first_player_pid] navy_positions\n", name);
    mini_printf("DESCRIPTION\n     first_player_pid: only for the 2nd pla");
    mini_printf("yer. pid of the first player.\n     navy_positions: file");
    mini_printf(" representing the positions of the ships.\n");
    return 0;
}

int is_correct_position(char *position)
{
    if (my_strlen(position) < 3 || my_strlen(position) > 3)
        return 1;
    if ((position[0] < 'A' || position[0] > 'H') ||
        (position[1] < '1' || position[1] > '8'))
        return 1;
    return 0;
}

void display_positions(game_t *game)
{
    mini_printf("\nmy navy:\n");
    mini_printf(" |A B C D E F G H\n");
    mini_printf("-+---------------\n");
    for (int i = 0; i < 8; i++) {
        mini_printf("%d|", i + 1);
        for (int j = 0; game->map1[i][j] != '\0'; j++)
            mini_printf("%c ", game->map1[i][j]);
        mini_printf("\n");
    }
    mini_printf("\nenemy navy:\n");
    mini_printf(" |A B C D E F G H\n");
    mini_printf("-+---------------\n");
    for (int i = 0; i < 8; i++) {
        mini_printf("%d|", i + 1);
        for (int j = 0; game->map2[i][j] != '\0'; j++)
            mini_printf("%c ", game->map2[i][j]);
        mini_printf("\n");
    }
}

char *case_hit(char *buffer)
{
    char *buff = malloc(sizeof(char) * 3);

    buff[0] = buffer[0];
    buff[1] = buffer[1];
    buff[2] = '\0';
    return (buff);
}

int is_hit(char c)
{
    if (c == '2' || c == '3' || c == '4' || c == '5')
        return 1;
    return 0;
}
