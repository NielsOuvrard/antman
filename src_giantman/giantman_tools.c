/*
** EPITECH PROJECT, 2022
** giantman_tools.c
** File description:
** tools du giantman tu connais
*/

#include "my.h"
#include "am_header.h"

void my_putfile (char *file, int len)
{
    write(0, file, len);
}
