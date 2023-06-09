/*
** EPITECH PROJECT, 2023
** recup_nbr.c
** File description:
** By Arthur M-D
*/

#include "lemin.h"

int recup_nbr(int y, char *str)
{
    int res = 0;
    int mul = 1;
    UINT j = 0;

    for (; str[j] == ' ' && str[j] != '\0'; j++);
    for (int i = 0; i < y; i++) {
        for (; str[j] < 58 && str[j] >= 48; j++);
        for (; str[j] != '\0' && str[j] == ' '; j++);
    }
    for (; str[j] != '\0' && str[j] != ' '; j++) {
        res *= mul;
        res += getnbr(str[j]);
        mul = 10;
    }
    return res;
}
