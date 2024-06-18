/*
** EPITECH PROJECT, 2023
** bootstrap
** File description:
** Header
*/

#include <stdarg.h>

#pragma once

void my_putchar(char c);
int my_putstr(char *str);
int my_put_nbr(int nb);
int my_strlen(char const *str);
int my_intlen(int nb);
int my_getnbr(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strdup(char const *src);
char **my_str_to_word_array(char const *str);
char *my_strncpy(char *dest, char const *src, int n);
int my_nbr_ispair(int nb);
int mini_printf(const char *format, ...);



typedef struct printf_s {
    char flags;
    int (*pf)(va_list);
} printf_t;

int my_character(va_list list);
int my_percent(va_list list);
int my_string(va_list list);
int my_number(va_list list);
