/*
** EPITECH PROJECT, 2021
** putstr.c
** File description:
** fichier affiche string
*/

#include <unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
