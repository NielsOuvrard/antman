/*
** EPITECH PROJECT, 2022
** antman_list_1.c
** File description:
** tools lite type 1
*/

#include "my.h"
#include "am_header.h"

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
