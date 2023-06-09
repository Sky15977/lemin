/*
** EPITECH PROJECT, 2023
** init_struct.c
** File description:
** By Arthur M-D
*/

#include "lemin.h"

int init_tunnels(file_info_t *info)
{
    info->i = 0;
    info->tunnels = malloc(sizeof(int *) * (info->nb_tunnels));
    info->tunnels[info->nb_tunnels - 1] = NULL;
    if (info->tunnels == NULL)
        return 84;
    for (int i = 0; i < info->nb_tunnels; i++)
        info->tunnels[i] = malloc(sizeof(int) * 2);
    for (int i = 0; i < info->nb_tunnels; i++)
        for (int j = 0; j < 2; j++)
            info->tunnels[i][j] = -1;
    return 0;
}

int init_room(file_info_t *info)
{
    info->loca = 0;
    info->room = malloc(sizeof(int *) * (info->nb_room));
    info->room[info->nb_room - 1] = NULL;
    if (info->room == NULL)
        return 84;
    for (int i = 0; i < info->nb_room; i++)
        info->room[i] = malloc(sizeof(int) * 4);
    for (int i = 0; i < info->nb_room; i++)
        for (int j = 0; j < 4; j++)
            info->room[i][j] = -1;
    return 0;
}

int *init_pos(file_info_t *info)
{
    int *pos = malloc(sizeof(int) * (info->ants + 1));

    pos[info->ants] = -3;
    for (int i = 0; i < info->ants; i++)
        pos[i] = -1;
    return pos;
}
