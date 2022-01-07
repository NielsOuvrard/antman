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
    if (type == 1)
        type_1(file);
    else if (type == 2)
        type_2(file);
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
    char *file = file_to_str(av[1]);
    if (file == NULL)
        return 84;
    antman(file, my_getnbr(av[2]));
    return 0;
}

// TYPES :
// 1 : lyr
// 2 : html
// 3 : ppm

// on regarde ligne par lignes
// pour chaque lignes, on check les 2 , puis les 3, les 4 ...
// (avec tous les groupes de mots possibles dans la ligne)
// premiers caracteres et on regarde combien de fois ils se répète dans le fichier

// on accorde une valeure à ce dictionnaire en fonction :
//      nombre d'apparition
//      taille

// on transforme avec le dictionnaire le plus intéressant le fichier
