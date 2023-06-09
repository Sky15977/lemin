/*
** EPITECH PROJECT, 2023
** check_file.c
** File description:
** By Arthur M-D
*/

#include "lemin.h"

static int room_exist(char *str)
{
    for (int j = 0; str[j]; j++)
        if (str[0] != '#' && str[j] == ' ')
            return 1;
    return 0;
}

static int check_room_exist(char **tab)
{
    int res = 0;

    for (int i = 0; tab[i]; i++)
        res += room_exist(tab[i]);
    return res;
}

int check_file(char **tab, int a, int b)
{
    int res = 10;

    if (a < 1 && b < 1)
        res = check_room_exist(tab);
    if (res == 0)
        return NO_ROOM;
    if (a < 1)
        return START;
    if (b < 1) {
        return END;
    }
    return 0;
}
