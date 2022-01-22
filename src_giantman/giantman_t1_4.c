/*
** EPITECH PROJECT, 2022
** antman_t1.c
** File description:
** type 1
*/

#include "my.h"
#include "am_header.h"

node_binary *creat_binaty_tree (list_val *caracters)
{
    if (!caracters)
        return NULL;
    head_node_binary *head = all_in_list_head(caracters);
    while (head->next != NULL) {
        head->next->node = concat_two_tree(head->node, head->next->node);
        head = head->next;
        head = sort_first_elem_head(head);
    }
    return head->node;
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

void compact_two_list (node_binary *tree, list_val *node)
{
    while (node != NULL) {
        find_the_binary_int_tree(tree, &node);
        node = node->next;
    }
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

void bits_char (char c, char *str, int *idx)
{
    for (int i = 0; i <= 7; i++) {
        str[*idx] = (c & (1 << i)) ? '1' : '0';
        (*idx)++;
    }
}
