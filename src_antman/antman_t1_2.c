/*
** EPITECH PROJECT, 2022
** antman_t1.c
** File description:
** type 1
*/

#include "my.h"
#include "am_header.h"

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

int find_and_disp_the_char (list_val *tree, char c, char *str, int *idx)
{
    while (tree) {
        if (tree->value == c) {
            for (int i = 1; i <= tree->binary[0]; i++) {
                str[(*idx)] = ITOC(tree->binary[i]);
                (*idx)++;
            }
            return tree->binary[0];
        }
        tree = tree->next;
    }
    return 0;
}

int size_of_malloc (list_val *tree, char c)
{
    while (tree) {
        if (tree->value == c)
            return tree->binary[0];
        tree = tree->next;
    }
    return 0;
}

// void printbits_two (char *str_bits)
// {
//     int j = 0;
//     while (1) {
//         int mask = 1;
//         char c = 0;
//         for (int i = j; i < j + 8; i++) {
//             if (str_bits[i] == '\0') {                  // C1
//                 my_putchar(c);
//                 return;
//             }
//             if (str_bits[i] == '1')
//                 c = (c | mask);
//             else if (str_bits[i] == '0' && (c & mask) != 0)
//                 c = (c ^ mask);
//             mask = mask * 2;
//         }
//         my_putchar(c);
//         j += 8;
//     }
// }

int printbits_two_next (char *str_bits, int *j)
{
    int mask = 1;
    char c = 0;
    for (int i = (*j); i < (*j) + 8; i++) {
        if (str_bits[i] == '\0') {
            my_putchar(c);
            return 0;
        }
        if (str_bits[i] == '1')
            c = (c | mask);
        else if (str_bits[i] == '0' && (c & mask) != 0)
            c = (c ^ mask);
        mask = mask * 2;
    }
    my_putchar(c);
    (*j) += 8;
    return 1;
}

void printbits_two (char *str_bits)
{
    int j = 0;
    while (printbits_two_next(str_bits, &j) == 1);
}
