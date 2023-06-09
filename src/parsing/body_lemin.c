/*
** EPITECH PROJECT, 2023
** body_lemin.c
** File description:
** By Arthur M-D
*/

#include "lemin.h"

void free_info(file_info_t *info, char **tab)
{
    if (info->start != NULL)
        free(info->start);
    if (info->end != NULL)
        free(info->end);
    if (info->room != NULL)
        free_array_int2d(info->room, info->nb_room - 1);
    if (info->tunnels != NULL)
        free_array_int2d(info->tunnels, info->nb_tunnels);
    if (tab != NULL)
        free_array_str2d(tab);
    free(info);
}

file_info_t *init_struct(void)
{
    file_info_t *in = malloc(sizeof(file_info_t));

    in->start = NULL;
    in->end = NULL;
    in->room = NULL;
    in->tunnels = NULL;
    return in;
}

int check_error(file_info_t *info, char **tab)
{
    int return_value = 0;
    int res = 0;

    return_value = check_no_pipe_room(info, tab);
    if (return_value != 0) {
        display_info(info, res, tab);
        return 84;
    }
    return_value = create_parsing(info, tab);
    if (return_value != 0)
        return 84;
    return_value = display_parsing(info);
    if (return_value != 0)
        return 84;
    res = process_algo_lemin(info);
    free_info(info, tab);
    return res;
}

int start_lemin(char *buffer)
{
    file_info_t *info = init_struct();
    char **tab = NULL;
    int res = 0;

    tab = str_to_word_array(buffer, '\n', '\n');
    free(buffer);
    res = error_handling_tab(tab);
    if (res != 0) {
        if (res == 6) {
            display_no_room(tab, info);
            return 84;
        }
        display_info(info, res, tab);
        return 84;
    }
    res = check_error(info, tab);
    return res;
}
