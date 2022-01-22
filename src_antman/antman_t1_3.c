/*
** EPITECH PROJECT, 2022
** antman_t1.c
** File description:
** type 1
*/

#include "my.h"
#include "am_header.h"

void disp_array (int *arr)
{
    for (int i = 1; i <= arr[0]; i++)
        my_printf("%d", arr[i]);
}

void makes_bits (node_binary* tree, int *bits, int top)
{
    if (tree->left) {
        bits[top] = 0;
        makes_bits(tree->left, bits, top + 1);
    }
    if (tree->right) {
        bits[top] = 1;
        makes_bits(tree->right, bits, top + 1);
    }
    if (!(tree->left) && !(tree->right)) {
        tree->binary = malloc(sizeof(int) * (top + 1));
        tree->binary[0] = top;
        for (int i = 0; i < top; i++)
            tree->binary[i + 1] = bits[i];
    }
}

void free_binary_tree (node_binary *tree)
{
    if (tree->left)
        free_binary_tree(tree->left);
    if (tree->right)
        free_binary_tree(tree->right);
    if (!(tree->left) && !(tree->right)) {
        free(tree);
        tree = NULL;
    }
}

void disp_char_occ (list_val *caracters)
{
    while (caracters) {
        my_putchar(caracters->value);
        my_putint(caracters->occ);
        my_putchar('|');
        caracters = caracters->next;
    }
}

void find_the_binary_int_tree (node_binary *tree, list_val **node)
{
    if (tree->left)
        find_the_binary_int_tree(tree->left, node);
    if (tree->right)
        find_the_binary_int_tree(tree->right, node);
    if (!(tree->left) && !(tree->right) && tree->value == (*node)->value)
        (*node)->binary = tree->binary;
}
