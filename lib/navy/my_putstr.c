/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** task02
*/

#include <unistd.h>
#include "navy.h"

int my_putstr(char *str)
{
    return write(1, str, my_strlen(str));
}
