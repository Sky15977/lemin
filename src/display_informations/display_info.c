/*
** EPITECH PROJECT, 2023
** display_info.c
** File description:
** By Arthur M-D
*/

#include "lemin.h"

int display_room_find(char *str)
{
    for (UINT y = 0; y < 2; y++) {
        my_putnbr(recup_nbr(y, str));
        my_putchar(' ');
    }
    my_putnbr(recup_nbr(2, str));
    my_putchar('\n');
    return 0;
}

void display_end(char *str)
{
    my_putstr("##end\n");
    for (UINT y = 0; y < 2; y++) {
        my_putnbr(recup_nbr(y, str));
        my_putchar(' ');
    }
    my_putnbr(recup_nbr(2, str));
    my_putchar('\n');
}

void display_start(char *str)
{
    my_putstr("##start\n");
    for (UINT y = 0; y < 2; y++) {
        my_putnbr(recup_nbr(y, str));
        my_putchar(' ');
    }
    my_putnbr(recup_nbr(2, str));
    my_putchar('\n');
}

int display_rooms_error(char **tab, int start, int end)
{
    for (int i = 0; tab[i]; i++) {
        if (start == 0 && my_strcmp(tab[i], "##start") == 0 )
            return START;
        if (end == 0 && my_strcmp(tab[i], "##end") == 0)
            return END;
        if ((tab[i][1] == ' ' || tab[i][2] == ' ')) {
            display_room_find(tab[i]);
        }
        if (my_strcmp(tab[i], "##start") == 0 && start > 0) {
            display_start(tab[i + 1]);
            start--;
            i += 1;
        }
        if (my_strcmp(tab[i], "##end") == 0 && end > 0) {
            display_end(tab[i + 1]);
            end--;
            i += 1;
        }
    }
    return 0;
}

void display_info(file_info_t *info, int error, char **tab)
{
    int start = 1;
    int end = 1;

    my_putstr("#number_of_ants\n");
    if (error == ANTS)
        return;
    get_ants(info, tab);
    if (info->ants > 0)
        my_putnbr(info->ants);
    my_putstr("\n#rooms\n");
    display_rooms_error(tab, start, end);
    if (error == ROOM || error == START || error == END)
        return;
    my_putstr("#tunnels\n");
    free_array_str2d(tab);
    free(info);
}
