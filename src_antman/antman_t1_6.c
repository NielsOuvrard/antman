/*
** EPITECH PROJECT, 2022
** antman_t1.c
** File description:
** type 1
*/

#include "my.h"
#include "am_header.h"

char *find_and_disp_sub_part(list_val *tree, int *idx, char *str)
{
    for (int i = 1; i <= tree->binary[0]; i++) {
        str[(*idx)] = ITOC(tree->binary[i]);
        (*idx)++;
    }
    return str;
}
