/*
** EPITECH PROJECT, 2022
** antman_list_1.c
** File description:
** tools lite type 1
*/

#include "my.h"
#include "am_header.h"


// int my_put_in_array_list (head_node_binary *array, list_val *list)
// {
//     head_node_binary *element;
//     element = malloc(sizeof(head_node_binary));
//     element->array
//     element->occ = occ;
//     element->next = *array;
//     *array = element;
//     return (0);
// }



void my_put_in_list_head (head_node_binary **head, node_binary *body)
{
    head_node_binary *element;
    element = malloc(sizeof(head_node_binary));
    element->node = body;
    element->next = *head;
    *head = element;
}

int my_put_in_list (list_val **list, char value, int occ)
{
    list_val *element;
    element = malloc(sizeof(list_val));
    element->value = value;
    element->occ = occ;
    element->next = *list;
    *list = element;
    return (0);
}

int free_linked_list_am (list_val *list)
{
    while (list != NULL) {
        list_val *tmp = list;
        // free(list->value);
        list = list->next;
        free(tmp);
    }
    free(list);
    return 0;
}

void disp_head_list (head_node_binary *head)
{
    while (head) {
        my_putstr("value : ");
        if (head->node->type == 0) {
            my_putchar(head->node->right->value);
            my_putchar('|');
            my_putchar(head->node->left->value);
        }
        if (head->node->value != '\n')
            my_putchar(head->node->value);
        else
            my_putstr("\\n");
        my_putstr("\tocc : ");
        my_putint(head->node->occ);
        my_putstr(" \tleft : ");
        my_putint(head->node->left != NULL ? head->node->left->occ : 0);
        my_putstr("\tright : ");
        my_putint(head->node->right != NULL  ? head->node->right->occ : 0);
        my_putchar('\n');
        head = head->next;
    }
}

// int disp_linked_list_am_2 (head_node_binary *list)
// {
//     my_printf("Array of list\tsize : %d\n", list->size);
//     for (int i = 0; list->array[i] != NULL; i++) {
//         my_putstr("value : ");
//         if (list->array[i]->value != '\n')
//             my_putchar(list->array[i]->value);
//         else
//             my_putstr("\\n");
//         my_putstr("\tocc : ");
//         my_putint(list->array[i]->occ);
//         my_putchar('\n');
//     }
//     return 1;
// }

int disp_linked_list_am (list_val *list)
{
    while (list != NULL) {
        my_putstr("value : ");
        if (list->value != '\n')
            my_putchar(list->value);
        else
            my_putstr("\\n");
        my_putstr("\tocc : ");
        my_putint(list->occ);
        my_putchar('\n');
        list = list->next;
    }
    return 1;
}

int my_list_size (list_val const *begin)
{
    int number = 0;
    while (begin != NULL) {
        number++;
        begin = begin->next;
    }
    return (number);
}

list_val *tail_linked_list (list_val *off)
{
    if (off == NULL)
        return off;
    while (off->next != NULL)
        off = off->next;
    list_val *tail = off;
    return tail;
}

void reverst_linked_list (list_val **off)
{
    list_val *list = NULL;
    for (int k = 0; *off != NULL; k++) {
        my_put_in_list(&list, (*off)->value, (*off)->occ);
        list_val *tmp = *off;
        (*off) = (*off)->next;
        free(tmp);
    }
    *off = list;
    return;
}

// void add_at_end (list_val **off, char *str)
// {
//     int size = my_list_size(*off);
//     list_val *list = NULL;
//     my_put_in_list(&list, str);
//     reverst_linked_list(off);
//     for (int k = size; k > 1 ; k--) {
//         my_put_in_list(&list, (*off)->str);
//         list_val *tmp = *off;
//         (*off) = (*off)->next;
//         free(tmp);
//     }
//     *off = list;
//     return;
// }


// list_val *tail_linked_list (list_val *off)
// {
//     if (off == NULL)
//         return off;
//     while (off->next != NULL)
//         off = off->next;
//     list_val *tail = off;
//     return tail;
// }
