/*
** EPITECH PROJECT, 2023
** open_read_file.c
** File description:
** By Arthur M-D
*/

#include "lemin.h"

char *recup_of_file_content(void)
{
    char *buffer = NULL;
    char *res = NULL;
    size_t size = 0;

    while (getline(&buffer, &size, stdin) != -1)
        res = my_strcat(res, buffer);
    free(buffer);
    return res;
}
