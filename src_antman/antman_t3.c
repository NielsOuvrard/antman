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

int len_line(char *file, int i)
{
    int res = 0;
    while (file[i] != '\0' && file[i] != '\n') {
        i++;
        res++;
    }
    return res;
}

int find_start(char *file)
{
    int res = len_line(file, 0), i = 0;
    while (file[i] != '\n')
        i++;
    i++;
    while (len_line(file, i) > 4) {
        i = i + len_line(file, i);
        i++;
    }
    return i;
}

int type_3 (char *file)
{
    int i = find_start(file), eee;
    for (int x = 0; x < i; x++)
        my_putchar(file[x]);
    my_putchar('|');
    for (i; file[i] != '\0'; i++) {
        eee = get_nbr2(file, i);
        my_putchar(nbrbi(eee));
        for (i; file[i] != '\n' && file[i] != '\0'; i++);
        eee = 0;
    }
    return 0;
}
