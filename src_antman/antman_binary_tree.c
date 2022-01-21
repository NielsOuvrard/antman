/*
** EPITECH PROJECT, 2022
** antman_tree_1.c
** File description:
** tools lite type 1
*/

#include "my.h"
#include "am_header.h"

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

int my_put_in_tree (node_binary **tree, char value, int occ, int a)
{
    node_binary *element;
    element = malloc(sizeof(node_binary));
    element->type = a % 10;
    if (element->type)
        element->value = value;
    else
        element->value = '\0';
    element->occ = occ;
    a /= 10;
    if (a)
        element->right = *tree;
    else
        element->left = *tree;
    *tree = element;
    return (0);
}

int disp_linked_tree_am (node_binary *tree)
{
    while (tree != NULL) {
        my_putchar(tree->value);
        my_putstr("\t");
        my_putint(tree->occ);
        my_putchar('\n');
        tree = tree->right;
    }
    return 1;
}

int my_tree_size (node_binary const *tree)
{
    int number = 0;
    while (tree) {
        number++;
        if (tree->right)
            tree = tree->right;
        else if (tree->left)
            tree = tree->left;
        else
            return number;
    }
    return number;
}
