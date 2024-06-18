/*
** EPITECH PROJECT, 2023
** main
** File description:
** MyNavy
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <ucontext.h>
#include "navy.h"
#include "game.h"

int *enemy_pid;

static void connection_signal(struct sigaction *sa,
    void (*pf)(int, siginfo_t *, void *))
{
    sa->sa_sigaction = pf;
    sigaction(SIGUSR2, sa, NULL);
    sigaction(SIGUSR1, sa, NULL);
    pause();
}

static void p1_connaction(int code, siginfo_t *info, void *extra)
{
    if (code == 12) {
        enemy_pid[0] = info->si_pid;
        mini_printf("enemy connected\n");
        kill(info->si_pid, SIGUSR2);
    }
}

static void p2_connaction(int code, siginfo_t *info, void *extra)
{
    if (code == 12) {
        enemy_pid[0] = info->si_pid;
        mini_printf("successfully connected\n");
    }
}

static int first_connexion(int ac, char **av, game_t *game)
{
    struct sigaction sa;
    siginfo_t *info;

    sa.sa_flags = SA_SIGINFO;
    mini_printf("my_pid: %d\n\n", getpid());
    if (ac == 2) {
        mini_printf("waiting for enemy connection...\n\n");
        connection_signal(&sa, &p1_connaction);
    } else {
        kill(my_getnbr(av[1]), SIGUSR2);
        connection_signal(&sa, &p2_connaction);
        game->in_queue = true;
    }
    return 0;
}

static void hit_or_missed(int code)
{
    if (code == 10)
        enemy_pid[3] = 1;
    if (code == 12)
        enemy_pid[3] = 2;
}

static void attack_enemy(char *line, game_t *game)
{
    struct sigaction sa;
    siginfo_t *info;
    int val = convert_cmd(line);

    send_attack(line);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_handler = hit_or_missed;
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
        return;
    if (sigaction(SIGUSR2, &sa, NULL) == -1)
        return;
    while (enemy_pid[3] == 0);
    update_enemy_map(game, val, line);
    enemy_pid[3] = 0;
    game->in_queue = true;
    game->pass = 0;
    game->round++;
}

static void defense_enemy(game_t *game)
{
    char *pos = NULL;
    int val = 0;
    int hit = 0;

    mini_printf("\nwaiting for enemy's attack...\n");
    pos = get_attack();
    val = convert_cmd(pos);
    if (is_hit(game->map1[(val - 1) % 8][(val - 1) / 8]) == 0) {
        game->map1[(val - 1) % 8][(val - 1) / 8] = 'o';
    } else {
        game->map1[(val - 1) % 8][(val - 1) / 8] = 'x';
        hit++;
    }
    update_hit(hit, pos);
    game->round++;
    game->in_queue = false;
}

static void true_or_false(char **line, size_t *len, game_t *game)
{
    int val = 0;

    if (game->in_queue == false) {
        mini_printf("\nattack: ");
        if (getline(line, len, stdin) == -1)
            return;
        val = convert_cmd(*line);
        if (is_correct_position(*line) == 1) {
            mini_printf("\nwrong position\n");
            game->pass = 1;
        } else {
            attack_enemy(*line, game);
        }
    } else {
        defense_enemy(game);
    }
}

static int my_navy(game_t *game)
{
    char *line = NULL;
    size_t len = 0;

    while (game->end == 0) {
        if (game->pass == 0 && my_nbr_ispair(game->round) == 0)
            display_positions(game);
        true_or_false(&line, &len, game);
        check_map(game);
        check_enemy_map(game);
    }
    display_positions(game);
    if (game->end == -1) {
        mini_printf("\nEnemy won\n");
        return 1;
    }
    if (game->end == 1) {
        mini_printf("\nI won\n");
        return 0;
    }
}

int main(int ac, char **av)
{
    game_t game = {0, 0, 0, NULL, NULL, false};

    if (ac < 2 || ac > 3)
        return 84;
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return usage(av[0]);
    if (open_file(ac, av, &game) == 84)
        return 84;
    enemy_pid = malloc(sizeof(int) * 4);
    enemy_pid[0] = 0;
    enemy_pid[1] = 0;
    enemy_pid[2] = 0;
    enemy_pid[3] = 0;
    first_connexion(ac, av, &game);
    return my_navy(&game);
}
