/*
** EPITECH PROJECT, 2023
** display_parsing.c
** File description:
** BY - CM
*/

#include "lemin.h"
int check_room_exist(file_info_t *info, int i)
{
    int counter = 0;

    for (int j = 0; j < info->nb_room; j++) {
        if (info->room[j][0] == info->tunnels[i][0] ||
        info->room[j][0] == info->tunnels[i][1])
            counter++;
    }
    if (info->tunnels[i][0] == info->tunnels[i][1] && counter == 1)
        return 1;
    if (counter != 2)
        return 0;
    else
        return 1;
}

int display_tunnels(file_info_t *info)
{
    my_putstr("#tunnels\n");
    for (int i = 0; i < info->nb_tunnels; i++) {
        if (check_room_exist(info, i) == 1) {
            my_putnbr(info->tunnels[i][0]);
            my_putchar('-');
            my_putnbr(info->tunnels[i][1]);
            my_putchar('\n');
        } else
            return 84;
    }
    return 0;
}

int display_rooms(file_info_t *info)
{
    my_putstr("\n#rooms\n");
    for (int i = 0; i < info->nb_room; i++) {
        if (info->room[i][3] == info->start[3])
            my_putstr("##start\n");
        if (info->room[i][3] == info->end[3])
            my_putstr("##end\n");
        if (info->err_coor != 0 && i == info->err_coor)
            return 1;
        if (info->err_name != 0 && i == info->err_name)
            return 1;
        my_putnbr(info->room[i][0]);
        my_putchar(' ');
        my_putnbr(info->room[i][1]);
        my_putchar(' ');
        my_putnbr(info->room[i][2]);
        my_putchar('\n');
    }
    return 0;
}

int display_parsing(file_info_t *info)
{
    int value = 0;

    my_putstr("#number_of_ants\n");
    my_putnbr(info->ants);
    value = display_rooms(info);
    if (value == 1)
        return 84;
    value = display_tunnels(info);
    if (value == 84)
        return 84;
    my_putstr("#moves\n");
    return 0;
}
