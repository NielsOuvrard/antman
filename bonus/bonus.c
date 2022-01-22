/*
** EPITECH PROJECT, 2021
** bonus
** File description:
** bonus
*/

#include "my.h"

void main(int ac, char **av)
{

    struct stat e, b;
    int un , deux;

    stat(av[2], &b);
    stat(av[1], &e);
    un = e.st_size;
    deux = b.st_size;
    my_putstr("taille premier fichier: \t");
    my_putnbr(un);
    my_putstr("\ntaille deuxieme fichier: \t");
    my_putnbr(deux);
    my_putstr("\ncompression de : ");
    my_putnbr(100*(deux)/un);
    my_putstr("%\n");
}
