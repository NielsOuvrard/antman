/*
** EPITECH PROJECT, 2022
** antman_t2.c
** File description:
** type 2
*/

#include "my.h"
#include "am_header.h"

int bi_dec(char i)
{
    int mask = 1, tot = 0;
    for (int x = 0; x < 8; x++) {
        if (!!(i & mask) == 1)
            tot = tot + mask;
        mask = mask * 2;
    }
    return tot;
}

int type_3 (char *file, int size)
{
    int i = 0;
    for (i; file[i] != '|'; i++)
        my_putchar(file[i]);
    i++;
    for (i; i < size; i++) {
        my_putunsint(bi_dec(file[i]));
        my_putchar('\n');
    }
    return 0;
}
