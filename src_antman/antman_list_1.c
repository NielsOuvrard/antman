/*
** EPITECH PROJECT, 2022
** antman_list_1.c
** File description:
** tools lite type 1
*/

#include "my.h"
#include "am_header.h"

int my_put_in_list (ls_type_1 **list, char *str)
{
    ls_type_1 *element;
    element = malloc(sizeof(ls_type_1));
    element->str = str;
    element->next = *list;
    *list = element;
    return (0);
}

int free_linked_list_am (ls_type_1 *list)
{
    while (list != NULL) {
        ls_type_1 *tmp = list;
        free(list->str);
        list = list->next;
        free(tmp);
    }
    free(list);
    return 0;
}

int disp_linked_list_am (ls_type_1 *list)
{
    while (list != NULL) {
        my_putstr(list->str);
        my_putchar('\n');
        list = list->next;
    }
    return 1;
}

int my_list_size (ls_type_1 const *begin)
{
    int number = 0;
    while (begin != NULL) {
        number++;
        begin = begin->next;
    }
    return (number);
}

ls_type_1 *tail_linked_list (ls_type_1 *off)
{
    if (off == NULL)
        return off;
    while (off->next != NULL)
        off = off->next;
    ls_type_1 *tail = off;
    return tail;
}

void reverst_linked_list (ls_type_1 **off)
{
    ls_type_1 *list = NULL;
    for (int k = 0; *off != NULL; k++) {
        my_put_in_list(&list, (*off)->str);
        ls_type_1 *tmp = *off;
        (*off) = (*off)->next;
        free(tmp);
    }
    *off = list;
    return;
}

void add_at_end (ls_type_1 **off, char *str)
{
    int size = my_list_size(*off);
    ls_type_1 *list = NULL;
    my_put_in_list(&list, str);
    reverst_linked_list(off);
    for (int k = size; k > 1 ; k--) {
        my_put_in_list(&list, (*off)->str);
        ls_type_1 *tmp = *off;
        (*off) = (*off)->next;
        free(tmp);
    }
    *off = list;
    return;
}


// ls_type_1 *tail_linked_list (ls_type_1 *off)
// {
//     if (off == NULL)
//         return off;
//     while (off->next != NULL)
//         off = off->next;
//     ls_type_1 *tail = off;
//     return tail;
// }
