/*
** EPITECH PROJECT, 2022
** antman_t1.c
** File description:
** type 1
*/

#include "my.h"
#include "am_header.h"

char *unlisible_to_bits (char *file, int str_size)
{
    int idx, size, idx_str_b = 0, i;
    while (my_strcmp(file, "|||"))
        file++;
    file += 3;
    char *size_bits = file;
    while (file[0] != '^')
        file++;
    file[0] = '\0';
    file++;
    int nmb_bits = my_getnbr(size_bits);
    size = str_size * 8;
    char *str_of_bits = malloc(sizeof(char) * size * 8);
    my_memset(str_of_bits, size * 8, '\0');
    for (i = 0; 8 * i < nmb_bits + 8; i++)
        bits_char(file[i], str_of_bits, &idx_str_b);
    str_of_bits[nmb_bits] = '\0';
    return str_of_bits;
}

list_val *dico_to_linked_list (char **dico)
{
    list_val *caracters = NULL;
    for (int i = 0; dico[i] != NULL; i++)
        my_put_in_list(&caracters, dico[i][0], my_getnbr(dico[i] + 1));
    return caracters;
}

void disp_array (int *arr)
{
    for (int i = 1; i <= arr[0]; i++)
        my_printf("%d", arr[i]);
}

void disp_tree (node_binary *tree)
{
    if (tree->left)
        disp_tree(tree->left);
    if (tree->right)
        disp_tree(tree->right);
    if (!(tree->left) && !(tree->right)) {
        my_printf("%c: ", tree->value);
        my_printf("\t occ : %d\t", tree->occ);
        disp_array(tree->binary);
        my_putchar('\n');
    }
}

void disp_the_nodes (list_val *list)
{
    while (list) {
        my_printf("char : %c\t", list->value);
        my_printf("occ : %d  \t", list->occ);
        my_printf("binary : ");
        disp_array(list->binary);
        my_putchar('\n');
        list = list->next;
    }
}
