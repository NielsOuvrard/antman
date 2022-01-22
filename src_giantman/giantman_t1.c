/*
** EPITECH PROJECT, 2022
** antman_t1.c
** File description:
** type 1
*/

#include "my.h"
#include "am_header.h"

int comparaison_arr_and_str (int *arr, char *str)
{
    for (int i = 0; arr[0] > i; i++)
        if (str[i] != ITOC(arr[i + 1]))
            return 0;
    return 1;
}

void bits_to_texte (list_val *cara, char *str)
{
    int j = 0;
    while (str) {
        int k = 0;
        list_val *expl = cara;
        while (expl && !comparaison_arr_and_str(expl->binary, str))
            expl = expl->next;
        if (!expl)
            return;
        for (int i = 0; expl->binary[0] > i && str[1] != '\0'; i++) {
            k = 1;
            str++;
        }
        if (!k) {
            my_putchar('\n');
            return;
        }
        my_putchar(expl->value);
    }
}

int type_1 (char *file, int str_size)
{
    char **dico = the_dico(file, str_size);
    list_val *caracters = dico_to_linked_list(dico);
    int size = my_list_size(caracters);
    node_binary *tree = creat_binaty_tree(caracters);
    int *bits = malloc(sizeof(int) * size);
    makes_bits(tree, bits, 0);
    free(bits);
    compact_two_list(tree, caracters);
    char *unlisible = unlisible_to_bits(file, str_size);
    bits_to_texte(caracters, unlisible);
    free(unlisible);
    while (caracters) {
        list_val *tmp = caracters;
        caracters = caracters->next;
        free(tmp);
    }
    for (int i = 0; dico[i] != NULL; i++)
        free(dico[i]);
    free(dico);
    return 0;
}
