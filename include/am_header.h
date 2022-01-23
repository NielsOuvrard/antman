/*
** EPITECH PROJECT, 2021
** header ls
** File description:
** ls
*/

#include "my.h"

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

typedef struct cell_t {
    int nbr;
    int total;
    struct cell_t *next;
    struct cell_t *prev;
} List, Cell;

typedef struct list_val {
    int *binary;
    char value;
    int occ;
    struct list_val *next;
} list_val;

typedef struct node_binary {
    int *binary;
    int type;
    char value;
    int occ;
    struct node_binary *left, *right;
} node_binary;

typedef struct head_node_binary {
    node_binary *node;
    struct head_node_binary *next;
} head_node_binary;

// giantman t1

int find_and_disp_the_char (list_val *tree, char c, char *str, int *idx);

int size_of_malloc (list_val *tree, char c);

void printbits_two (char *str_bits);

void free_binary_tree (node_binary *tree);

void disp_char_occ (list_val *caracters);

char **the_dico (char *file, int size);

node_binary *concat_two_tree (node_binary *tree_1, node_binary *tree_2);

head_node_binary *all_in_list_head (list_val *caracters);

head_node_binary *sort_first_elem_head (head_node_binary *head);

node_binary *creat_binaty_tree (list_val *caracters);

void find_the_binary_int_tree (node_binary *tree, list_val **node);

void compact_two_list (node_binary *tree, list_val *node);

void makes_bits (node_binary* tree, int *bits, int top);

void bits_char (char c, char *str, int *idx);

char *unlisible_to_bits (char *file, int str_size);

list_val *dico_to_linked_list (char **dico);

void disp_array (int *arr);

void disp_tree (node_binary *tree);

void disp_the_nodes (list_val *list);

// head

void my_put_in_list_head (head_node_binary **head, node_binary *body);

int disp_linked_list_am_2 (head_node_binary *list);

void disp_head_list (head_node_binary *head);

// body

node_binary *first_elem (char value, int occ, int type);

int my_put_in_tree (node_binary **tree, char value, int occ, int a);

int disp_linked_tree_am (node_binary *tree);

int my_tree_size (node_binary const *tree);

// bientot suppr car opti :

list_val *in_new_list (list_val *caracters, char *file, int i);

int is_sorted (list_val *caracters);

void sort_one_time (list_val *caracters);

list_val *sort_according_to_occ (list_val *caracters);

list_val *new_list (char *file);

int my_put_in_list (list_val **list, char value, int occ);

int free_linked_list_am (list_val *list);

int disp_linked_list_am (list_val *list);

int my_list_size (list_val const *begin);

list_val *tail_linked_list (list_val *off);

void reverst_linked_list (list_val **off);

// op on files

char *file_to_str (char *file_name, int *size, int *error);

void my_putfile (char *file, int len);

// dump

void dump_array_str (char **map);

void dump_arr_int (int *arr);

// types

int type_1 (char *file, int size);

int type_3 (char *file, int size);

// list type 1

static Cell *createcell(int nbr, int total);

List *emptylist(void);

int isemptylist(List *L);

void printlist(List *L);

List *freelist(List *L);

int getat(List *L, int pos);

int lenlist(List *L);

void setat(List *L, int pos, int nbr, int total);

List *freeat(List *L, int pos);

List *addat(List *L, int nbr, int total, int pos);

void addend(int nbr, int total, List **enda, List **list);

//antman t3.2

int get_nbr2(char *yes, int i);

void readbitsc(char a);

void readbitsint(int a);

void printbits(char *it, char *a);
