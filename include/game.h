/*
** EPITECH PROJECT, 2023
** Players
** File description:
** Header
*/

#include <stdbool.h>

#pragma once

typedef struct game_s {
    int end;
    int round;
    int pass;
    int *hit;
    char **map1;
    char **map2;
    bool in_queue;
} game_t;

extern int *enemy_pid;

int usage(char *name);
int is_correct_position(char *position);
void display_positions(game_t *game);
char *case_hit(char *buffer);
int open_file(int ac, char **av, game_t *game);
void send_attack(char *cmd);
char *get_attack(void);
int convert_cmd(char *cmd);
int is_hit(char c);
void update_enemy_map(game_t *game, int val, char *line);
void update_hit(int hit, char *pos);
void check_map(game_t *game);
void check_enemy_map(game_t *game);
