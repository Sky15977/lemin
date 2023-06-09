/*
** EPITECH PROJECT, 2022
** str
** File description:
** str_is_num
*/
#include "../../includes/tools.h"
#include <unistd.h>
#include <stdlib.h>

int str_is_num(const char *str)
{
    if (!str)
        return (FALSE);
    for (int i = 0; str[i] != '\0'; i++) {
        if (char_is_num(str[i]) != TRUE)
            return (FALSE);
    }
    return (TRUE);
}
