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
    // if (a) {
    //     node_binary *tmp = tree->right;
    //     tree->right = element;
    //     element->right = tmp;
    // } else {
    //     node_binary *tmp = tree->left;
    //     tree->left = element;
    //     element->left = tmp;
    // }
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

// int free_linked_tree_am (node_binary *tree)      // compliqué
// {
//     while (tree != NULL) {
//         node_binary *tmp = tree;
//         tree = tree->right;
//         free(tmp);
//     }
//     free(tree);
//     return 0;
// }


// node_binary *tail_linked_tree (node_binary *tree)
// {
//     if (tree == NULL)
//         return tree;
//     while (tree->right != NULL)
//         tree = tree->right;
//     node_binary *tail = tree;
//     return tail;
// }

// void reverst_linked_tree (node_binary **off)
// {
//     node_binary *tree = NULL;
//     for (int k = 0; *off != NULL; k++) {
//         my_put_in_tree(&tree, (*off)->str, (*off)->a);
//         node_binary *tmp = *off;
//         (*off) = (*off)->next;
//         free(tmp);
//     }
//     *off = tree;
//     return;
// }

// void add_at_end (node_binary **off, char *str)
// {
//     int size = my_tree_size(*off);
//     node_binary *tree = NULL;
//     my_put_in_tree(&tree, str);
//     reverst_linked_tree(off);
//     for (int k = size; k > 1 ; k--) {
//         my_put_in_tree(&tree, (*off)->str);
//         node_binary *tmp = *off;
//         (*off) = (*off)->next;
//         free(tmp);
//     }
//     *off = tree;
//     return;
// }


// node_binary *tail_linked_tree (node_binary *off)
// {
//     if (off == NULL)
//         return off;
//     while (off->next != NULL)
//         off = off->next;
//     node_binary *tail = off;
//     return tail;
// }
