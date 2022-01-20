/*
** EPITECH PROJECT, 2022
** antman_t1.c
** File description:
** type 1
*/

#include "my.h"
#include "am_header.h"

int my_put_in_tree (node_binary **tree, char value, int occ, int a);

list_val *in_new_list (list_val *caracters, char *file, int i)
{
    list_val *expl = caracters;
    while (expl) {
        if (file[i] == expl->value) {
            expl->occ++;
            return caracters;
        }
        expl = expl->next;
    }
    my_put_in_list(&caracters, file[i], 1);
    return caracters;
}

int is_sorted (list_val *caracters)
{
    while (caracters && caracters->next) {
        if (caracters->occ > caracters->next->occ)
            return 0;
        caracters = caracters->next;
    }
    return 1;
}

void sort_one_time (list_val *caracters)
{
    while (caracters && caracters->next) {
        if (caracters->occ > caracters->next->occ) {
            char c_tmp = caracters->value;
            int i_tmp = caracters->occ;
            caracters->value = caracters->next->value;
            caracters->occ = caracters->next->occ;
            caracters->next->value = c_tmp;
            caracters->next->occ = i_tmp;
        }
        caracters = caracters->next;
    }
    return;
}

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
    // my_printf("total occ : %d\n", occ);
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
    while (head != NULL && head->next != NULL && head->next->node->occ < to_order->node->occ)
        head = head->next;
    head_node_binary *tmp = head->next;
    head->next = to_order;
    to_order->next = tmp;
    return head_returned;
}

node_binary *creat_binaty_tree (list_val *caracters)
{
    if (!caracters)
        return NULL;
    head_node_binary *head = all_in_list_head(caracters);
    // disp_head_list(head);

    while (head->next != NULL) {
        // my_printf("on cocat %c", head->node->value);
        // my_printf(" \tavec %c\n", head->next->node->value);
        head->next->node = concat_two_tree(head->node, head->next->node);
        head = head->next;
        head = sort_first_elem_head(head);
    }
    // disp_head_list(head);
    return head->node;
}

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
        // my_printf("%c: ", tree->value);
        // bits[top] = '\0';
        // disp_array(bits, top);
        // int *bits = malloc(sizeof(int) * top);
        tree->binary = malloc(sizeof(int) * (top + 1));
        // bits[0] = top;
        tree->binary[0] = top;
        for (int i = 0; i < top; i++)
            tree->binary[i + 1] = bits[i];
        // disp_array(tree->binary, top);
        // my_printf("%s\n", bits);
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
    //     return tree->binary;
    // return tree->binary;
}

void compact_two_list (node_binary *tree, list_val *node)
{
    while (node != NULL) {
        find_the_binary_int_tree(tree, &node);
        node = node->next;
    }
}

void disp_the_nodes (list_val *list)
{
    while (list) {
        my_printf("char : %c\t", list->value);
        my_printf("occ : %d  \t", list->occ);
        my_printf("binary : ");
        // my_printf("taille bits : %d\n", list->binary[0]);
        // disp_array(list->binary);
        disp_array(list->binary);
        my_putchar('\n');
        list = list->next;
    }
}

void find_and_disp_the_char (list_val *tree, char c, char *str, int *idx)
{
    while (tree) {
        if (tree->value == c) {
            for (int i = 1; i <= tree->binary[0]; i++) {
                str[(*idx)] = ITOC(tree->binary[i]);
                (*idx)++;
            }
            disp_array(tree->binary);
            // my_putchar(' ');
            return;
        }
        tree = tree->next;
    }
    return;
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

void printbits_two (char *str_bits)
{
    int j = 0;
    while (str_bits[j] != '\0') {
        int mask = 1;
        char c = 0;
        for (int i = j; i < j + 8; i++) {
            if (str_bits[i] == '\0') {
                my_putchar(c);
                my_putint(i - j);
                return;
            }
            if (str_bits[i] == '1')
                c = (c | mask);
            else if (str_bits[i] == '0' && (c & mask) != 0)
                c = (c ^ mask);
            mask = mask * 2;
        }
        my_putchar(c);
        j += 8;
    }
    my_putchar('0');
}

// void printbits_paul (char *it, char c) {
//     int mask = 1;
//     for (int i = 0; i < 8; i++) {
//         if (it[i] == '1')
//             c = (c | mask);
//         else if (it[i] == '0' && (c & mask) != 0)
//             c = (c ^ mask);
//         mask = mask * 2;
//     }
// }

// return status pour return le truc de ls là


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

int type_1 (char *file)
{
    list_val *caracters = new_list(file);
    disp_char_occ(caracters);
    my_putchar('|');
    int size = my_list_size(caracters);
    reverst_linked_list(&caracters);
    // disp_linked_list_am(caracters);
    node_binary *tree = creat_binaty_tree(caracters);
    int *bits = malloc(sizeof(int) * size);
    makes_bits(tree, bits, 0);
    free(bits);
    compact_two_list(tree, caracters);
    // disp_tree(tree);
    // my_printf("\n\n\n\n");
    // disp_array(caracters->binary, 3);
    // disp_the_nodes(caracters);
    int malloc_sz = 0, index_str = 0;
    for (int i = 0; file[i] != '\0'; i++)
        malloc_sz += size_of_malloc(caracters, file[i]);
    my_putchar('\n');
    char *str_bits = malloc(sizeof(char) * (malloc_sz + 1));
    my_memset(str_bits, malloc_sz + 1, '\0');
    for (int i = 0; file[i] != '\0'; i++)
        find_and_disp_the_char(caracters, file[i], str_bits, &index_str);
    // my_putstr(str_bits);
    // my_putchar('\n');
    // printbits_two(str_bits);
    // for (int i = 0; str_bits[i] != '\0'; i++) {
    //     printbits_two(str_bits, i);
    //     i += 7;
    // }
    // while (tree->right != NULL && tree->left != NULL)
    //     free_binary_tree(tree);
    return 0;
}

// on met le nombre de 0 qu'il y a en plus dans le dernier bit

// output: g1000| 000|e010|01010

// |a124|f64|h34| 23| ...

// si négatif en décompression, faire + 256
