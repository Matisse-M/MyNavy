/*
** EPITECH PROJECT, 2023
** my_nbr_ispair
** File description:
** Return 0 if it's pair 1 if it's not
*/

int my_nbr_ispair(int nb)
{
    if (nb == 0)
        return 0;
    if (nb == 1)
        return 1;
    return (nb % 2);
}
