/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** By Arthur M-D
*/

#include "lemin.h"

int main(int ac, char **av)
{
    char *buffer = NULL;
    int res = 0;

    if (ac == 2 && (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == 0))
        return manage_usage();
    if (ac != 1)
        return manage_error();
    buffer = recup_of_file_content();
    if (buffer == NULL)
        return 84;
    res = start_lemin(buffer);
    return res;
}
