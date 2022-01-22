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

int test_nbr(char *file, int i)
{
    while (file[i] != '\n') {
        if (file[i] < 48 || file[i] > 57)
            return 1;
        i++;
    }
    return 0;
}

int find_start(char *file)
{
    int i = 0;
    while (test_nbr(file, i) == 1) {
        for (i; file[i] != '\n'; i++) {
            my_putchar(file[i]);
        }
        my_putchar(file[i]);
        i++;
    }
    my_putchar('|');
    return i;
}

int type_3 (char *file, int cbnjh)
{
    int i = find_start(file), eee;
    for (i; file[i] != '\0'; i++) {
        eee = get_nbr2(file, i);
        my_putchar(nbrbi(eee));
        for (i; file[i] != '\n' && file[i] != '\0'; i++);
        eee = 0;
    }
    return 0;
}
