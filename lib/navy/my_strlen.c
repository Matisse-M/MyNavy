/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** Return the length of a string
*/

#include "navy.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}
