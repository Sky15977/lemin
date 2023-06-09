/*
** EPITECH PROJECT, 2023
** fill_visited.c
** File description:
** By Arthur M-D
*/

#include "lemin.h"

int number_three(int *nbr, file_info_t *info)
{
    for (int j = 1; j < info->nb_room; j++) {
        if (nbr[j] == 3)
            return 1;
    }
    return 0;
}

int search_nb_three(solve_tab_t *tab, file_info_t *info)
{
    int nbr = 0;

    for (int i = 1; i < info->nb_room; i++)
        nbr += number_three(tab->tab[i], info);
    return nbr;
}

void fill_visited(solve_tab_t *tab, file_info_t *info)
{
    for (int i = 0; i < info->nb_room; i++)
        tab->visited[i] = -1;
}
