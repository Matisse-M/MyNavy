/*
** EPITECH PROJECT, 2023
** parsing
** File description:
** Create map
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include "navy.h"
#include "game.h"

static int allowed_coord(char i, char j, char x, char y)
{
    if (i < 'A' || i > 'H' || x < 'A' || x > 'H' ||
        j < '1' || j > '8' || y < '1' || y > '8')
        return 84;
    return 0;
}

static int check_coord(char *line)
{
    char letter_a = line[2];
    char letter_b = line[5];
    char number_a = line[3];
    char number_b = line[6];

    if (allowed_coord(letter_a, number_a, letter_b, number_b) == 84)
        return 84;
    if (letter_a == letter_b) {
        if ((number_b - number_a) == (line[0] - '0' - 1))
            return 0;
        return 84;
    }
    if (number_a == number_b) {
        if ((letter_b - letter_a) == (line[0] - '0' - 1))
            return 0;
        return 84;
    }
    return 84;
}

static int check_lines(char *line, char *ship_nb, int x)
{
    int len = 0;

    while (line[len] != '\n')
        len++;
    if (len != 7)
        return 84;
    if (line[0] < '2' || line[0] > '5')
        return 84;
    if (line[0] < '2' + x)
        return 84;
    for (int i = 0; i < 4; i++)
        if (ship_nb[i] == '0') {
            ship_nb[i] = line[0];
            break;
        }
    if (line[1] != ':' || line[4] != ':')
        return 84;
    return check_coord(line);
}

static int fill_boats(char **map, char *line)
{
    char letter_a = line[2] - 'A';
    char letter_b = line[3] - '1';
    char number_a = line[5] - 'A';
    char number_b = line[6] - '1';
    int len = my_getnbr(line);
    int i = (number_a - letter_a) / (len - 1);
    int j = (number_b - letter_b) / (len - 1);

    for (int k = 0; k < len; k++) {
        if (map[letter_b + j * k][letter_a + i * k] != '.')
            return 84;
        map[letter_b + j * k][letter_a + i * k] = len + '0';
    }
    return 0;
}

static char **empty_map(void)
{
    char *map = malloc(sizeof(char) * 73);
    char **result = NULL;
    int c = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            map[c] = '.';
            c++;
        }
        map[c] = '\n';
        c++;
    }
    map[72] = '\0';
    result = my_str_to_word_array(map);
    free(map);
    return result;
}

static char **create_map(char *file)
{
    FILE *fd = fopen(file, "r");
    char *line = NULL;
    char **map = empty_map();
    char *ship_nb = malloc(sizeof(char) * 4);
    size_t len = 0;
    int x = 0;

    if (fd == NULL)
        return NULL;
    for (int k = 0; k < 4; k++)
        ship_nb[k] = '0';
    for (int i = 0; i < 4; i++) {
        getline(&line, &len, fd);
        if (check_lines(line, ship_nb, x) == 84)
            return NULL;
        if (fill_boats(map, line) == 84)
            return NULL;
        x++;
    }
    return map;
}

int open_file(int ac, char **av, game_t *game)
{
    int index = 1;

    if (ac == 3)
        index = 2;
    game->map1 = create_map(av[index]);
    if (game->map1 == NULL)
        return 84;
    game->map2 = empty_map();
    return (0);
}
