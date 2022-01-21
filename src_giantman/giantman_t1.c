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

char *unlisible_to_bits (char *file, int str_size)
{
    int idx, size, idx_str_b = 0, i;
    while (file[0] != '|' || file[1] != '|')
        file++;
    file += 2;
    char *size_bits = file;
    while (file[0] != '^')
        file++;
    file[0] = '\0';
    file++;
    int nmb_bits = my_getnbr(size_bits);
    size = str_size * 8;
    char *str_of_bits = malloc(sizeof(char) * size * 8);
    my_memset(str_of_bits, size * 8, '\0');
    for (i = 0; 8 * i < nmb_bits + 8; i++)
        bits_char(file[i], str_of_bits, &idx_str_b);
    str_of_bits[nmb_bits] = '\0';
    return str_of_bits;
}

list_val *dico_to_linked_list (char **dico)
{
    list_val *caracters = NULL;
    for (int i = 0; dico[i] != NULL; i++)
        my_put_in_list(&caracters, dico[i][0], my_getnbr(dico[i] + 1));
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

int comparaison_arr_and_str (int *arr, char *str)
{
    for (int i = 0; arr[0] > i; i++)
        if (str[i] != ITOC(arr[i + 1]))
            return 0;
    return 1;
}

void bits_to_texte (list_val *cara, char *str)
{
    int j = 0;
    while (str) {
        list_val *expl = cara;
        while (expl && !comparaison_arr_and_str(expl->binary, str))
            expl = expl->next;
        if (!expl)
            return;
        my_putchar(expl->value);
        for (int i = 0; expl->binary[0] > i && str[1] != '\0'; i++)
            str++;
        // my_printf("\nchar num %d\n", j++);
    }
}

int type_1 (char *file, int str_size)
{
    char **dico = the_dico(file);
    list_val *caracters = dico_to_linked_list(dico);
    int size = my_list_size(caracters);
    node_binary *tree = creat_binaty_tree(caracters);
    int *bits = malloc(sizeof(int) * size);
    makes_bits(tree, bits, 0);
    free(bits);
    compact_two_list(tree, caracters);
    char *unlisible = unlisible_to_bits(file, str_size);
    bits_to_texte(caracters, unlisible);
    free(unlisible);
    while (caracters) {
        list_val *tmp = caracters;
        caracters = caracters->next;
        free(tmp);
    }
    for (int i = 0; dico[i] != NULL; i++)
        free(dico[i]);
    free(dico);
    return 0;
}
