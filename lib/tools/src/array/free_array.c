/*
** EPITECH PROJECT, 2022
** array
** File description:
** free_array
*/
#include "../../includes/tools.h"
#include <unistd.h>
#include <stdlib.h>

void free_array_str2d(char **str)
{
    int i = 0;

    while (str[i] != NULL) {
        if (str[i] != NULL)
            free(str[i]);
        i++;
    }
    free(str);
}

void free_array_int2d(int **int2d, int line)
{
    int i = 0;

    if (!int2d)
        return;
    for (; i < line; i++)
            free(int2d[i]);
    free(int2d);
}
