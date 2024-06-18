/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** Duplicate a string
*/

#include <stdio.h>
#include <stdlib.h>
#include "navy.h"

char *my_strdup(char const *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    int i = 0;

    while (*src) {
        dest[i] = *src;
        i++;
        src++;
    }
    dest[i] = '\0';
    return (dest);
}
