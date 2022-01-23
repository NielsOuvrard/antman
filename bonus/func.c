/*
** EPITECH PROJECT, 2021
** functions
** File description:
** functions
*/

#include "my.h"

char my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int e = 0;
    while (str[e] != '\0') {
        my_putchar(str[e]);
        e = e + 1;
    }
}

int my_putnbr(int n)
{
    if (n < 0) {
        my_putchar('-');
        n = n * (-1);
    }
    if (n >= 10) {
        my_putnbr(n / 10);
        my_putchar(n % 10 + '0');
    }
    if (n < 10) {
        my_putchar(n % 10 + '0');
    }
    return (n);
}
