/*
** EPITECH PROJECT, 2022
** antman_t1.c
** File description:
** type 1
*/

#include "my.h"
#include "am_header.h"

char **the_dico (char *file)
{
    int words = 0, i, idx_dico = 0;
    for (int i = 0; file[i] != '\0'; i++)
        if (file[i] == '@')
            words++;
    char **dico = malloc(sizeof(char *) * (words + 1));
    for (i = 0; file[i] != '|'; i++) {
        int sz = 0, i_dico = 0;
        for (sz = i; file[sz] != '@'; sz++);
        dico[idx_dico] = malloc(sizeof(char) * (sz + 1));
        my_memset(dico[idx_dico], sz + 1, '\0');
        for (i; file[i] != '@'; i++) {
            dico[idx_dico][i_dico] = file[i];
            i_dico++;
        }
        idx_dico++;
    }
    dico[idx_dico] = NULL;
    return dico;
}

void dico_to_file (char **dico, char *file)
{
    int i, size = my_strlen(file);
    for (i = 0; file[i] != '|'; i++);
    for (i++; i < size; i++) {
        if (file[i + 1] == '\0')
            return;
        int nmb = 0;
        for (i; i < size && file[i] != '|' && file[i] != '\n' && file[i] != '^'; i++) {
            nmb += CTOI(file[i]);
            nmb *= 10;
        }
        nmb /= 10;
        my_putstr(dico[nmb]);
        if (file[i] == '^')
            my_putchar('\n');
        else if (file[i] == '|')
            my_putchar(' ');
        if (file[i] == '?')
            i = i;
    }
    return;
}

int type_1 (char *file)
{
    char **dico = the_dico(file);
    dico_to_file(dico, file);
    for (int i = 0; dico[i] != NULL; i++)
        free(dico[i]);
    free(dico);
    return 0;
}
