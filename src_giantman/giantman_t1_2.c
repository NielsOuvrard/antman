/*
** EPITECH PROJECT, 2022
** antman_t1.c
** File description:
** type 1
*/

#include "my.h"
#include "am_header.h"

list_val *sort_according_to_occ (list_val *caracters)
{
    while (!is_sorted(caracters))
        sort_one_time(caracters);
    return caracters;
}

list_val *new_list (char *file)
{
    list_val *caracters = NULL;
    for (int i = 0; file[i] != '\0'; i++)
        caracters = in_new_list(caracters, file, i);
    caracters = sort_according_to_occ(caracters);
    return caracters;
}

node_binary *concat_two_tree (node_binary *tree_1, node_binary *tree_2)
{
    int occ = tree_1->occ + tree_2->occ;
    node_binary *tree = first_elem('\0', occ, 0);
    tree->right = tree_1;
    tree->left = tree_2;
    return tree;
}

head_node_binary *all_in_list_head (list_val *caracters)
{
    head_node_binary *linked_list = NULL;
    while (caracters) {
        my_put_in_list_head(&linked_list, first_elem(caracters->value, caracters->occ, 1));
        caracters->binary = NULL;
        caracters = caracters->next;
    }
    return linked_list;
}

head_node_binary *sort_first_elem_head (head_node_binary *head)
{
    if (head->next == NULL || head->node->occ <= head->next->node->occ)
        return head;
    head_node_binary *head_returned = head->next;
    head_node_binary *to_order = head;
    head = head->next;
    while (head != NULL && head->next != NULL &&
    head->next->node->occ < to_order->node->occ)
        head = head->next;
    head_node_binary *tmp = head->next;
    head->next = to_order;
    to_order->next = tmp;
    return head_returned;
}
