/*
** EPITECH PROJECT, 2022
** antman_t2.c
** File description:
** type 2
*/

#include "my.h"
#include "am_header.h"

char nbrbi(int a)
{
    int mask = 1;
    char e = 0x00000000;
    for (int x = 0; x < 8; x++) {
        if (!!(a & mask) == 1)
            e = (e | mask);
        mask = mask * 2;
    }
    return e;
}

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
