/*
** EPITECH PROJECT, 2023
** check_no_pipe_room.c
** File description:
** By Arthur M-D
*/

#include "lemin.h"

int check_no_pipe_room(file_info_t *info, char **tab)
{
    int tunnel = count_nbr_tunnels(info, tab);
    int room = count_nbr_room(info, tab);

    if (room == 0)
        return ROOM;
    if (tunnel == 0)
        return TUNNELS;
    return 0;
}
