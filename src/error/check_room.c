/*
** EPITECH PROJECT, 2023
** check_room.c
** File description:
** BY - CM
*/

#include "lemin.h"

int check_room_coordinate(file_info_t *info, int i)
{
    int j = i + 1;

    for (; j < info->nb_room; j++)
        if (info->room[i][1] == info->room[j][1] &&
            info->room[i][2] == info->room[j][2])
            return j;
    return FALSE;
}

int check_room_name(file_info_t *info, int i)
{
    int j = i + 1;

    for (; j < info->nb_room; j++)
        if (info->room[i][0] == info->room[j][0])
            return j;
    return FALSE;
}

void check_room_error(file_info_t *info)
{
    int i = 0;
    int name = 0;
    int coor = 0;

    info->err_name = 0;
    info->err_coor = 0;
    for (; i < info->nb_room; i++) {
        name = check_room_name(info, i);
        coor = check_room_coordinate(info, i);
        if (info->err_name == 0 || (name != 0 && name < info->err_name))
            info->err_name = name;
        if (info->err_coor == 0 || (coor != 0 && coor < info->err_coor))
            info->err_coor = coor;
    }
}
