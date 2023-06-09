/*
** EPITECH PROJECT, 2023
** create_tab.c
** File description:
** By Lukas Anne
*/

#include "lemin.h"

int **fill_tunnels(int **array, file_info_t *info)
{
    int tmp1 = 0;
    int tmp2 = 0;

    for (int i = 0; i < info->nb_tunnels; i++) {
        tmp1 = info->tunnels[i][0] + 1;
        tmp2 = info->tunnels[i][1] + 1;
        if (tmp1 > info->nb_room || tmp2 > info->nb_room)
            return NULL;
        array[tmp2][tmp1] = 1;
        array[tmp1][tmp2] = 1;
    }
    return array;
}

int **fill_tab(int **array, file_info_t *info)
{
    for (int i = 1; array[i]; i++)
        for (int j = 1; j < info->nb_room; j++)
            array[i][j] = 0;
    return array;
}

int **init_tab(int **array, file_info_t *info)
{
    int fill = 0;

    array[0][0] = 99;
    for (int i = 0; array[i]; i++) {
        for (int j = 1; j < info->nb_room; j++) {
            array[i][j] = fill;
            fill++;
        }
        fill = 0;
    }
    for (int i = 1; array[i]; i++) {
        array[i][0] = fill;
        fill++;
    }
    if (!array) {
        write(2, "Error: fill array\n", 19);
        return NULL;
    }
    fill_tab(array, info);
    return array;
}

int **alloc_tab(file_info_t *info)
{
    int i = 0;
    info->nb_room += 1;
    int **array = malloc(sizeof(int *) * (info->nb_room + 1));
    array[info->nb_room] = NULL;
    if (!array) {
        write(2, "Error: Alloc memory\n", 21);
        return NULL;
    }
    for (; i < info->nb_room; i++) {
        for (int j = 0; j < info->nb_room; j++) {
            array[i] = malloc(sizeof(int) * (info->nb_room + 1));
            array[i][info->nb_room] = -1;
        }
    }
    array[i] = NULL;
    if (!array) {
        write(2, "Error: Alloc memory\n", 21);
        return NULL;
    }
    return array;
}

int process_algo_lemin(file_info_t *info)
{
    solve_tab_t *array = malloc(sizeof(solve_tab_t));
    int **tab = alloc_tab(info);
    int res = 0;

    tab = init_tab(tab, info);
    array->tab = fill_tunnels(tab, info);
    res = bfs_main(info, array);
    return res;
}
