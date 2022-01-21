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

// avant arbres binaires :

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

char *file_to_str (char *file_name, int *size);

void my_putfile (char *file, int len);

// char **str_to_array (char *str);

// dump

void dump_array_str (char **map);

void dump_arr_int (int *arr);

// types

int type_1 (char *file, int size);

int type_3 (char *file);

// list type 1

// int free_linked_list_am (ls_type_1 *list);

// int my_put_in_list (ls_type_1 **list, char *str, int a);

// int disp_linked_list_am (ls_type_1 *list);

// int my_list_size (ls_type_1 const *begin);

// ls_type_1 *tail_linked_list (ls_type_1 *l_1);

// void add_at_end (ls_type_1 **list, char *str);

// void reverst_linked_list (ls_type_1 **off);

// chained list list.c



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
