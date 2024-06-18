/*
** EPITECH PROJECT, 2023
** protocol
** File description:
** function to catch signal
*/

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "game.h"

int convert_cmd(char *cmd)
{
    char sig1 = cmd[0];
    char sig2 = cmd[1];
    int result = 0;

    for (char i = 'A'; i < 'I'; i++) {
        if (i == sig1) {
            result += (i - 'A') * 8;
            break;
        }
    }
    for (char i = '1'; i <= '9'; i++) {
        if (i == sig2) {
            result += (i - '1');
            break;
        }
    }
    return result + 1;
}

static char *convert_cde(int cde)
{
    char *cmd = malloc(sizeof(char) * 2);

    cmd[0] = 64 + (cde - 1) / 8 + 1;
    cmd[1] = 49 + (cde - 1) % 8;
    return cmd;
}

void send_attack(char *cmd)
{
    int nb_kill = convert_cmd(cmd);

    for (int i = 0; i < nb_kill; i++) {
        kill(enemy_pid[0], SIGUSR1);
        usleep(100);
    }
    kill(enemy_pid[0], SIGUSR2);
}

static void which_sig(int code)
{
    if (code == 10)
        enemy_pid[2]++;
    if (code == 12)
        enemy_pid[1] = 1;
}

char *get_attack(void)
{
    struct sigaction sa;
    siginfo_t *info;
    char *output;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_handler = which_sig;
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
        return NULL;
    if (sigaction(SIGUSR2, &sa, NULL) == -1)
        return NULL;
    while (enemy_pid[1] == 0);
    output = convert_cde(enemy_pid[2]);
    enemy_pid[1] = 0;
    enemy_pid[2] = 0;
    return (output);
}
