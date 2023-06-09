/*
** EPITECH PROJECT, 2023
** fill_element.c
** File description:
** By Arthur M-D
*/

#include "lemin.h"

void fill_room_end(file_info_t *info)
{
    info->end[0] = info->room[info->loca][0];
    info->end[1] = info->room[info->loca][1];
    info->end[2] = info->room[info->loca][2];
    info->end[3] = info->room[info->loca][3];
}

void fill_room_start(file_info_t *info)
{
    info->start[0] = info->room[info->loca][0];
    info->start[1] = info->room[info->loca][1];
    info->start[2] = info->room[info->loca][2];
    info->start[3] = info->room[info->loca][3];
}
