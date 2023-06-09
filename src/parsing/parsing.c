/*
** EPITECH PROJECT, 2023
** parsing.c
** File description:
** By Arthur M-D
*/

#include "lemin.h"

int get_tunnel(file_info_t *info, char **tab)
{
    for (UINT y = 0; y < 2; y++)
        info->tunnels[info->i][y] = my_getnbr_int(tab[y]);
    return 0;
}

int get_room(file_info_t *info, char *str)
{
    for (UINT y = 0; y < 3; y++)
        info->room[info->loca][y] = recup_nbr(y, str);
    info->room[info->loca][3] = info->loca;
    return 0;
}

int get_room_tunnel(file_info_t *info, char *str)
{
    char **tab = NULL;

    for (UINT i = 0; str[i]; i++) {
        if (str[i] == '-') {
            tab = str_to_word_array(str, '-', '-');
            get_tunnel(info, tab);
            free_array_str2d(tab);
            info->i++;
            return 0;
        }
        if (str[i] == ' ' && str[0] != '#') {
            get_room(info, str);
            info->loca++;
            return 0;
        }
    }
    return 1;
}

int get_start_end(file_info_t *info, char **tab, unsigned int *y)
{
    if (my_strcmp(tab[*y], "##start") == 0) {
        info->start = malloc(sizeof(int) * 4);
        get_room(info, tab[*y + 1]);
        fill_room_start(info);
        info->loca++;
        *y += 2;
    }
    if (my_strcmp(tab[*y], "##end") == 0) {
        info->end = malloc(sizeof(int) * 4);
        get_room(info, tab[*y + 1]);
        fill_room_end(info);
        info->loca++;
        *y += 2;
    }
    return 0;
}

int create_parsing(file_info_t *info, char **tab)
{
    UINT y = 0;

    for (; my_strncmp(tab[y], "#", 1) == 0 && tab[y]; y++);
    info->ants = my_getnbr_int(tab[y]);
    info->nb_room = count_nbr_room(info, tab);
    info->nb_tunnels = count_nbr_tunnels(info, tab);
    if (info->nb_room < 2 || info->nb_tunnels < 1)
        return 1;
    init_room(info);
    init_tunnels(info);
    for (; tab[y]; y++) {
        get_start_end(info, tab, &y);
        get_start_end(info, tab, &y);
        if (tab[y] == NULL)
            return 0;
        get_room_tunnel(info, tab[y]);
    }
    check_room_error(info);
    return 0;
}
