/*
** EPITECH PROJECT, 2023
** test_bfs.c
** File description:
** BY - EL
*/

#include "lemin.h"

int *change_way(int *way, file_info_t *info)
{
    int i = 0;
    int buffer = 0;
    int middle;

    for (; way[i] != -1; i++);
    i--;
    way[i] = info->end[0];
    middle = i / 2;
    i--;
    for (int x = 0; middle > x; x++, i--) {
        buffer = way[x];
        way[x] = way[i];
        way[i] = buffer;
    }
    return way;
}

void browse_tab(solve_tab_t *tab, file_info_t *info)
{
    int j = info->start[0] + 1;
    int pointer = 0;
    tab->here = 0;
    tab->visited = malloc(sizeof(int) * (info->nb_room + 1));

    mark_line(tab, info->start[0] + 1, info);
    tab->visited[info->nb_room] = - 2;
    fill_visited(tab, info);
    if (end_visited(tab, info) == 1)
        tab->tab[info->end[0] + 1][j] = 2;
    while (end_visited(tab, info) != 1) {
        if (tab->visited[pointer] == -2) {
            tab->visited = NULL;
            return;
        }
        search_end(tab, j, info);
        j = tab->visited[pointer];
        pointer++;
    }
}

int find_length(solve_tab_t *tab, file_info_t *info)
{
    int counter = 0;
    int j = 0;

    browse_tab(tab, info);
    j = info->end[0] + 1;
    if (tab->visited == NULL)
        return 0;
    while (start_visited(tab, info) != 1) {
        j = search_start(tab, j, info);
        counter++;
    }
    if (counter == 1 && search_nb_three(tab, info) == 2)
        return counter;
    return counter;
}

int *smaller_way(file_info_t *info, solve_tab_t *tab)
{
    int j = 1;
    int length_way = find_length(tab, info);
    int *way = malloc(sizeof(int) * (length_way + 1));
    int value = 0;

    if (length_way <= 0)
        return NULL;
    way[length_way] = -1;
    j = info->end[0] + 1;
    if (length_way == 1) {
        way[value] = info->start[0];
        return way;
    }
    while (start_visited_second(tab, info) != 1) {
        j = search_final_way(tab, j, info);
        way[value] = j - 1;
        value++;
    }
    return way;
}

int bfs_main(file_info_t *info, solve_tab_t *tab)
{
    int *way = smaller_way(info, tab);

    if (way == NULL)
        return 84;
    way = change_way(way, info);
    display_path(info, way);
    return 0;
}
