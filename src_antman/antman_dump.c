/*
** EPITECH PROJECT, 2022
** antman_dump.c
** File description:
** dump file
*/

#include "my.h"
#include "am_header.h"

void dump_array_str (char **map)
{
    int i;
    for (i = 0; map[i] != NULL; i++) {
        my_putint(i);
        my_putstr("\t: ");
        for (int k = 0; map[i][k] != '\0'; k++) {           // C1
            if (map[i][k] != '\n')
                my_putchar(map[i][k]);
            else
                my_putstr("'\\n'");
        }
        my_putstr("\n");
    }
    my_putint(i);
    my_putstr("\t: NULL\n\n");
    return;
}

void dump_arr_int (int *arr)
{
    for (int i = 1; i < arr[0]; i++) {
        my_putint(arr[i]);
        my_putchar('\n');
    }
    my_putchar('\n');
    return;
}
