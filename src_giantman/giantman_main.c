/*
** EPITECH PROJECT, 2022
** giantman_main.c
** File description:
** le main du giantman tu connais
*/

#include "my.h"
#include "am_header.h"

int giantman (char *file, int type, int size)
{
    if (type == 1)
        type_1(file, size);
    else if (type == 2)
        type_1(file, size);
    else
        type_3(file);
    free(file);
    return 0;
}

int main (int ac, char **av)
{
    if (ac != 3)
        return 84;
    if (my_strcmp(av[2], "1") && my_strcmp(av[2], "2")
    && my_strcmp(av[2], "3"))
        return 84;
    int size = 0;
    char *file = file_to_str(av[1], &size);
    if (file == NULL)
        return 84;
    giantman(file, my_getnbr(av[2]), size);
    return 0;
}