/*
** EPITECH PROJECT, 2022
** antman_t1.c
** File description:
** type 1
*/

#include "my.h"
#include "am_header.h"

char **the_dico (char *file)
{
    int words = 0, i, idx_dico = 0;
    for (int i = 0; file[i] != '\0'; i++)
        if (file[i] == '|')
            words++;
    char **dico = malloc(sizeof(char *) * (words + 1));
    for (i = 0; file[i] != '|'; i++) {
        int sz = 0, i_dico = 0;
        for (sz = i; file[sz] != '|'; sz++);
        dico[idx_dico] = malloc(sizeof(char) * (sz + 1));
        my_memset(dico[idx_dico], sz + 1, '\0');
        for (i; file[i] != '|'; i++) {
            dico[idx_dico][i_dico] = file[i];
            i_dico++;
        }
        idx_dico++;
    }
    dico[idx_dico] = NULL;
    return dico;
}


// void dico_to_file (char **dico, char *file)
// {
//     int i, size = my_strlen(file);
//     for (i = 0; file[i] != '|'; i++);
//     for (i++; i < size; i++) {
//         if (file[i + 1] == '\0')
//             return;
//         int nmb = 0;
//         for (i; i < size && file[i] != '|' && file[i] != '\n' && file[i] != '^'; i++) {
//             nmb += CTOI(file[i]);
//             nmb *= 10;
//         }
//         nmb /= 10;
//         my_putstr(dico[nmb]);
//         if (file[i] == '^')
//             my_putchar('\n');
//         else if (file[i] == '|')
//             my_putchar(' ');
//         if (file[i] == '?')
//             i = i;
//     }
//     return;
// }
// char & (1u << base)

int my_put_in_tree (node_binary **tree, char value, int occ, int a);

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
        // my_putchar((c & (1 << i)) ? '1' : '0' );
    }
}

////// antman t1

char *unlisible_to_bits (char *file)
{
    int idx, size, idx_str_b = 0, i;
    for (idx = 0; file[idx] != '|' || file[idx + 1] != '|'; idx++);
    idx += 2;
    // char *no_dico = &file[idx];
    file += idx;
    // my_putstr("file :\n");
    // my_putstr(file);

    size = my_strlen(file) - idx;
    // char *bits = malloc(sizeof(char) * (size + 1));
    char *str_of_bits = malloc(sizeof(char) * (size + 1) * 8);
    my_memset(str_of_bits, (size + 1) * 8, '\0');
    // my_memset(bits, size + 1, '\0');
    // my_strcpy(bits, file + idx);
    // my_putchar('\n');
    for (i = 0; file[i] != '\0'; i++)
        bits_char(file[i], str_of_bits, &idx_str_b);
    int to_suppr = CTOI(file[i - 1]);
    // my_printf("to suppr : %d\n", to_suppr);
    str_of_bits[my_strlen(str_of_bits) - to_suppr] = '\0';
    return str_of_bits;
}

list_val *dico_to_linked_list (char **dico)
{
    list_val *caracters = NULL;
    for (int i = 0; dico[i] != NULL; i++)
        my_put_in_list(&caracters, dico[i][0], my_getnbr(dico[i] + 1));
    // disp_linked_list_am(caracters);
    // reverst_linked_list(&caracters);
    // my_putstr("\n\n");
    // disp_linked_list_am(caracters);
    return caracters;
}


void disp_array (int *arr)
{
    for (int i = 1; i <= arr[0]; i++)
        my_printf("%d", arr[i]);
}

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
    char **dico = the_dico(file);
    // my_show_word_array(dico);
    list_val *caracters = dico_to_linked_list(dico);
    // disp_linked_list_am(caracters);
    // node_binary *tree = creat_binaty_tree(caracters);
    int size = my_list_size(caracters);
    // reverst_linked_list(&caracters);
    node_binary *tree = creat_binaty_tree(caracters);
    int *bits = malloc(sizeof(int) * size);
    makes_bits(tree, bits, 0);
    free(bits);
    compact_two_list(tree, caracters);
    // disp_tree(tree);

    char *unlisible = unlisible_to_bits(file);
    // my_printf("ok les bits seuls :\n");
    my_putstr(unlisible);
    // node_binary *tree = dic_to_tree(dico);
    // for (int i = 0; file[i] '')
    // dico_to_file(dico, file);
    for (int i = 0; dico[i] != NULL; i++)
        free(dico[i]);
    free(dico);
    return 0;
}
