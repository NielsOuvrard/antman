/*
** EPITECH PROJECT, 2022
** antman_t3_2.c
** File description:
** type 3_2
*/

#include "my.h"
#include "am_header.h"

int get_nbr2(char *yes, int i)
{
    int res = 0, x = i, neg = 1;
    if (yes[x] == '-' || yes[x] == '+') {
        if (yes[x] == '-')
            neg = -1;
        x++;
    }
    while (yes[x] <= 57 && yes[x] >= 48) {
        res = res * 10;
        res = res + (yes[x] - 48);
        x++;
    }
    res = res * neg;
    return res;
}

void readbitsc(char a)
{
    int mask = 1;

    for (int x = 0; x < 8;x++) {
        my_putunsint(!!(a & mask));
        mask = mask * 2;
    }
}

void readbitsint(int a)
{
    int mask = 1;
    for (int x = 0; x < 8;x++) {
        my_putunsint(!!(a & mask));
        mask = mask * 2;
    }
}

void printbits(char *it, char *a)
{
    int mask = 1;
    for (int i = 0; i < 8; i++) {
        if (it[i] == '1')
            *a = (*a | mask);
        else if (it[i] == '0' && (*a & mask) != 0)
            *a = (*a ^ mask);
        mask = mask * 2;
    }
}
