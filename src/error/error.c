/*
** EPITECH PROJECT, 2023
** error.c
** File description:
** error
*/

#include "lemin.h"

int manage_error(void)
{
    my_putstr("./lem_in: bad arguments\n");
    my_putstr("retry with -h\n");
    return 84;
}

int manage_usage(void)
{
    my_putstr("USAGE:\n\t./lem_in < [Config file].\n");
    my_putstr("DESCRIPTION:\n\t[Config file]: Contain the main ");
    my_putstr("information for run as well this program.\n");
    return 0;
}
