/*
** EPITECH PROJECT, 2022
** antman_t1.c
** File description:
** type 1
*/

#include "my.h"
#include "am_header.h"

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

list_val *type_1_next (char *file, int *size)
{
    list_val *caracters = new_list(file);
    disp_char_occ(caracters);
    my_putstr("||");
    (*size) = my_list_size(caracters);
    reverst_linked_list(&caracters);
    return caracters;
}

int type_1 (char *file, int marvin)
{
    int size;
    list_val *caracters = type_1_next(file, &size);
    node_binary *tree = creat_binaty_tree(caracters);
    int *bits = malloc(sizeof(int) * size);
    makes_bits(tree, bits, 0);
    free(bits);
    compact_two_list(tree, caracters);
    int malloc_sz = 0, index_str = 0;
    for (int i = 0; file[i] != '\0'; i++)
        malloc_sz += size_of_malloc(caracters, file[i]);
    char *str_bits = malloc(sizeof(char) * (malloc_sz + 1));
    my_memset(str_bits, malloc_sz + 1, '\0');
    int nmb_bits = 0;
    for (int i = 0; file[i] != '\0'; i++)
        nmb_bits += find_and_disp_the_char(
        caracters, file[i], str_bits, &index_str);
    my_putint(nmb_bits);
    my_putchar('^');
    printbits_two(str_bits);
    return 0;
}
