/*
** EPITECH PROJECT, 2023
** error_handling_tab.c
** File description:
** BY - CM
*/

#include "lemin.h"

int check_tunnel(char **tab)
{
    for (UINT y = 0; y < 2; y++)
        if (str_is_num(tab[y]) != TRUE)
            return TUNNELS;
    return 0;
}

int check_room(char **tab)
{
    for (UINT y = 0; y < 3; y++)
        if (str_is_num(tab[y]) != TRUE)
            return ROOM;
    return 0;
}

int check_room_tunnel(char *str)
{
    int res = 0;
    char **tab = NULL;

    for (UINT i = 0; str[i]; i++) {
        if (str[i] == '-') {
            tab = str_to_word_array(str, '-', '-');
            res = check_tunnel(tab);
            free_array_str2d(tab);
            return res;
        }
        if (str[0] != '#' && str[i] == ' ') {
            tab = str_to_word_array(str, ' ', ' ');
            res = check_room(tab);
            free_array_str2d(tab);
            return res;
        }
    }
    return 0;
}

int check_start_end(char **tab, unsigned int *y, int *a, int *b)
{
    int res = 0;

    if (my_strcmp(tab[*y], "##start") == 0)
        (*a)++;
    if (my_strcmp(tab[*y], "##end") == 0)
        (*b)++;
    if ((*a) > 1)
        return START;
    if ((*b) > 1)
        return END;
    for (; my_strncmp(tab[*y], "#", 1) == 0 && tab[*y]; (*y)++)
        return 0;
    if (tab[*y] == NULL)
        return -1;
    if ((res = check_room_tunnel(tab[*y])) != 0)
        return res;
    return 0;
}

int error_handling_tab(char **tab)
{
    int a = 0;
    int b = 0;
    UINT y = 0;
    int res = 0;

    for (; my_strncmp(tab[y], "#", 1) == 0 && tab[y]; y++);
    if (str_is_num(tab[y]) != TRUE)
        return ANTS;
    for (; tab[y]; y++) {
        if ((res = check_start_end(tab, &y, &a, &b)) > 0)
            return res;
        if (res == -1)
            break;
    }
    res = check_file(tab, a , b);
    return res;
}
