/*
** EPITECH PROJECT, 2023
** diplay_path.c
** File description:
** BY - CM
*/

#include "lemin.h"

static int pos_finish(file_info_t *info, int *pos)
{
    int i = info->ants;

    for (; i > 0 ; i--)
        if (pos[i - 1] != -2)
            return 1;
    return 0;
}

static void display_ants_pos(int *pos)
{
    int i = 0;

    for (i = 0; pos[i] != -3; i++) {
        if (pos[i] != -1 && pos[i] != -2) {
            my_putchar('P');
            my_putnbr(i + 1);
            my_putchar('-');
            my_putnbr(pos[i]);
        }
        if (pos[i + 1] != -3 && pos[i + 1] != -1 && pos[i + 1] != -2
            && pos[i] != -1 && pos[i] != -2)
            my_putchar(' ');
    }
    my_putchar('\n');
    return;
}

static int search_way(int *way, int pos)
{
    int i = 0;

    if (pos == -2)
        return pos;
    for (; way[i] != -1; i++)
        if (way[i] == pos)
            return i;
    return -1;
}

static void change_pos(int *way, int *pos, int end)
{
    int res = 0;
    int i = 0;

    for (; pos[i] != -3; i++) {
        res = search_way(way, pos[i]);
        if (res == -1) {
            pos[i] = way[0];
            return;
        }
        if (pos[i] != end && pos[i] != -2)
            pos[i] = way[res + 1];
        else
            pos[i] = -2;
    }
}

void display_path(file_info_t *info, int *way)
{
    int end = info->end[0];
    int *pos = init_pos(info);

    for (int i = 0; pos_finish(info, pos) != 0; i++) {
        change_pos(way, pos, end);
        if (pos_finish(info, pos) == 0)
            break;
        display_ants_pos(pos);
    }
    return;
}
