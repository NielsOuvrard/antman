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
        type_3(file, size);
    free(file);
    return 0;
}

int file_exist (char *filepath)
{
    int file = open(filepath, O_RDONLY);
    if (file <= 0)
        return 0;
    close(file);
    return 1;
}

int main (int ac, char **av)
{
    if (ac != 3)
        return 84;
    if (my_strcmp(av[2], "1") && my_strcmp(av[2], "2")
    && my_strcmp(av[2], "3"))
        return 84;
    int size = 0, error = 0;
    if (!file_exist(av[1]))
        return 84;
    char *file = file_to_str(av[1], &size, &error);
    if (file == NULL) {
        if (error == 84)
            return 84;
        my_putchar('\n');
        return 0;
    }
    giantman(file, my_getnbr(av[2]), size);
    return 0;
}
