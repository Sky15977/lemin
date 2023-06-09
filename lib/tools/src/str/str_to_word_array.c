/*
** EPITECH PROJECT, 2022
** str
** File description:
** str_to_word_array
*/
#include "../../includes/tools.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static int number_chara(char *str, int i, char c, char c2)
{
    int words = 0;

    for (; (str[i] == c2 || str[i] == c) && str[i] != '\0'; i++);
    for (; str[i] != '\0' && str[i] != c && str[i] != c2; i++)
        words++;
    return words;
}

static int number_lines(char *str, char c, char c2)
{
    int i = 0;
    int lines = 0;

    while ( str[i] != '\0') {
        if ((str[i] != c && str[i] != c2) && (str[i + 1] == c
        || str[i + 1] == c2 || str[i + 1] == '\0'))
            lines++;
        i++;
    }
    return lines;
}

char **str_to_word_array(char *const str, char c, char c2)
{
    int lines = number_lines(str, c, c2);
    char **array = malloc(sizeof(char*) * (lines + 1));
    int i = 0;
    int j = 0;
    int k = 0;

    for (;i != lines; i++) {
        array[i] = malloc(sizeof(char) * (number_chara(str, k, c, c2) + 1));
        array[i][number_chara(str, k, c, c2)] = '\0';
        for (;(str[k] == c || str[k] == c2) && str[k] != '\0'; k++);
        for (;str[k] != c && str[k] != '\0' && str[k] != c2; k++) {
            array[i][j] = str[k];
            j++;
        }
        j = 0;
    }
    array[lines] = NULL;
    return array;
}
