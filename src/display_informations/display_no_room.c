/*
** EPITECH PROJECT, 2023
** display_no_room.c
** File description:
** By Arthur M-D
*/

#include "lemin.h"

void display_no_room(char **tab, file_info_t *info)
{
    my_putstr("#number_of_ants\n");
    get_ants(info, tab);
    if (info->ants > 0)
        my_putnbr(info->ants);
    my_putstr("\n#rooms\n");
}
