/*
** EPITECH PROJECT, 2022
** antman_main.c
** File description:
** le main du antman tu connais
*/

#include "my.h"
#include "am_header.h"

int antman (char *file, int type)
{
    if (type == 1 || type == 2)
        type_1(file, type);
    else if (type == 2)
        type_1(file, type);
    else
        type_3(file, type);
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
    antman(file, my_getnbr(av[2]));
    return 0;
}
