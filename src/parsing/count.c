/*
** EPITECH PROJECT, 2023
** count_nbr_room.c
** File description:
** By Arthur M-D
*/

#include "lemin.h"

int count_nbr_tunnels(file_info_t *info, char **tab)
{
    int i = 0;
    int count = 0;

    for (; tab[i][0] == '#'; i++);
    i++;
    for (; tab[i]; i++) {
        for (; tab[i][0] == '#' && tab[i + 1] != NULL; i++);
        for (; tab[i][0] == '#' && tab[i][1] == '#'; i++)
            i++;
        if (tab[i][1] == '-' || tab[i][2] == '-')
            count++;
    }
    info->nb_tunnels = count + 2;
    return count;
}

int count_nbr_room(file_info_t *info, char **tab)
{
    int i = 0;
    int count = 0;

    for (; tab[i][0] == '#'; i++);
    i++;
    for (; tab[i]; i++) {
        for (; tab[i][0] == '#' && tab[i + 1] != NULL; i++);
        for (; tab[i][0] == '#' && tab[i][1] == '#'; i++)
            i++;
        if (tab[i][0] != '#' && (tab[i][1] == ' ' || tab[i][2] == ' '))
            count++;
    }
    info->nb_room = count + 2;
    return count;
}
