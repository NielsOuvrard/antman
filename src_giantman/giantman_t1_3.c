/*
** EPITECH PROJECT, 2022
** antman_t1.c
** File description:
** type 1
*/

#include "my.h"
#include "am_header.h"

char **the_dico (char *file, int size)              /// too long
{
    int words = 0, i, idx_dico = 0;
    for (int i = 0; i < size; i++)
        if (file[i] == '|' && (file[i - 1] >= '0' && file[i - 1] <= '9'))
            words++;
    char **dico = malloc(sizeof(char *) * (words + 1));
    for (i = 0; file[i] != '|' || file[i + 1] != '|'; i++) {
        int sz = 0, i_dico = 0;
        for (sz = i + 1; file[sz] != '|'; sz++);
        dico[idx_dico] = malloc(sizeof(char) * (sz + 2));
        my_memset(dico[idx_dico], sz + 2, '\0');
        while (file[i + 1] != '|') {
            dico[idx_dico][i_dico] = file[i];
            i_dico++;
            i++;
        }
        dico[idx_dico][i_dico] = file[i];
        i_dico++;
        i++;
        idx_dico++;
    }
    dico[idx_dico] = NULL;
    return dico;
}

node_binary *first_elem (char value, int occ, int type)
{
    node_binary *element;
    element = malloc(sizeof(node_binary));
    element->value = value;
    element->type = type;
    element->occ = occ;
    element->right = NULL;
    element->left = NULL;
    return element;
}

list_val *in_new_list (list_val *caracters, char *file, int i)
{
    list_val *expl = caracters;
    while (expl) {
        if (file[i] == expl->value) {
            expl->occ++;
            return caracters;
        }
        expl = expl->next;
    }
    my_put_in_list(&caracters, file[i], 1);
    return caracters;
}

int is_sorted (list_val *caracters)
{
    while (caracters && caracters->next) {
        if (caracters->occ > caracters->next->occ)
            return 0;
        caracters = caracters->next;
    }
    return 1;
}

void sort_one_time (list_val *caracters)
{
    while (caracters && caracters->next) {
        if (caracters->occ > caracters->next->occ) {
            char c_tmp = caracters->value;
            int i_tmp = caracters->occ;
            caracters->value = caracters->next->value;
            caracters->occ = caracters->next->occ;
            caracters->next->value = c_tmp;
            caracters->next->occ = i_tmp;
        }
        caracters = caracters->next;
    }
    return;
}
