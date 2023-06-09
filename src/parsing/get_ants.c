/*
** EPITECH PROJECT, 2023
** get_ants.c
** File description:
** By Arthur M-D
*/

#include "lemin.h"

void get_ants(file_info_t *info, char **tab)
{
    int y = 0;

    for (; my_strncmp(tab[y], "#", 1) == 0 && tab[y]; y++);
    info->ants = my_getnbr_int(tab[y]);
}
