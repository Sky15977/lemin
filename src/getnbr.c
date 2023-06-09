/*
** EPITECH PROJECT, 2022
** getnbr.c
** File description:
** By Arthur M-D
*/

int getnbr(char c)
{
    int digit = 0;

    if (c < 58 && c > 47) {
        digit = c - 48;
        return digit;
    } else
        return -1;
}
