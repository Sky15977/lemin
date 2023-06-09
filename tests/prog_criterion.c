/*
** EPITECH PROJECT, 2023
** test_criterion.c
** File description:
** BY - CM
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "lemin.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(lemin, check_prog, .init = redirect_all_std)
{
    char str[] = "3\n2 5 0\n##start\n0 1 0\n##end\n1 13 0 #bedroom\n3 9 0\n#The next room is the kitchen\n0-2\n2-3\n3-1\n";

    start_lemin(str);
    cr_assert_stdout_eq_str("#number_of_ants\n3\n#rooms\n2 5 0\n##start\n0 1 0\n##end\n1 13 0\n3 9 0\n#tunnels\n0-2\n2-3\n3-1\n");
}
