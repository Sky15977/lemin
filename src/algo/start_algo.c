/*
** EPITECH PROJECT, 2023
** starting algo
** File description:
** start_algo
*/

#include "lemin.h"

void mark_line_way(solve_tab_t *tab, int i, file_info_t *info)
{
    for (int j = 1; j < info->nb_room; j++)
        if (tab->tab[i][j] == 3)
            tab->tab[i][j] = 4;
}

int search_final_way(solve_tab_t *tab, int j, file_info_t *info)
{
    for (int i = 1; i < info->nb_room; i++)
        if (tab->tab[i][j] == 3) {
            mark_line_way(tab, i, info);
            return i;
        }
    return 0;
}

int search_start(solve_tab_t *tab, int j, file_info_t *info)
{
    for (int i = 1; i < info->nb_room; i++) {
        if (tab->tab[i][j] == 2) {
            mark_line_second(tab, i, info);
            j = i;
        }
    }
    return j;
}

void search_end(solve_tab_t *tab, int j, file_info_t *info)
{
    for (int i = 1; i < info->nb_room; i++) {
        if (tab->tab[i][j] == 1) {
            tab->visited[tab->here] = i;
            mark_line(tab, i, info);
            tab->here++;
        }
    }
}
