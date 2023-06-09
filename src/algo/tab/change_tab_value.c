/*
** EPITECH PROJECT, 2023
** B-CPE-200-REN-2-1-lemin-matthew.charuel
** File description:
** change_tab_value
*/

#include "lemin.h"

int start_visited_second(solve_tab_t *tab, file_info_t *info)
{
    for (int i = 1; i < info->nb_room; i++)
        if (tab->tab[i][info->start[0] + 1] == 4)
            return 1;
    return 0;
}

int start_visited(solve_tab_t *tab, file_info_t *info)
{
    for (int i = 1; i < info->nb_room; i++)
        if (tab->tab[info->start[0] + 1][i] == 3)
            return 1;
    return 0;
}

int end_visited(solve_tab_t *tab, file_info_t *info)
{
    for (int i = 1; i < info->nb_room; i++)
        if (tab->tab[i][info->end[0] + 1] == 2)
            return 1;
    return 0;
}

void mark_line_second(solve_tab_t *tab, int i, file_info_t *info)
{
    for (int j = 1; j < info->nb_room; j++)
        if (tab->tab[i][j] == 2)
            tab->tab[i][j] = 3;
}

void mark_line(solve_tab_t *tab, int i, file_info_t *info)
{
    for (int j = 1; j < info->nb_room; j++)
        if (tab->tab[i][j] == 1)
            tab->tab[i][j] = 2;
}
