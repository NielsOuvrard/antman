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

}List, Cell;

typedef struct ls_type_1 {
    char *str;
    struct ls_type_1 *next;
} ls_type_1;

// typedef struct linked_list_ps {
//     int nbr;
//     struct linked_list_ps *next;
// } linked_list_ps;

typedef struct type_1_opt {
    int opti;
    int same;
    int i;

} type_1_opt;

// op on files

char *file_to_str (char *file_name);

// char **str_to_array (char *str);

// dump

void dump_array_str (char **map);

void dump_arr_int (int *arr);

void dump_arr_int_str (char **map, int *arr_int);

// types

int type_1 (char *file);

int type_2 (char *file);

int type_3 (char *file);

// list type 1

int free_linked_list_am (ls_type_1 *list);

int my_put_in_list (ls_type_1 **list, char *str);

int disp_linked_list_am (ls_type_1 *list);

int my_list_size (ls_type_1 const *begin);

ls_type_1 *tail_linked_list (ls_type_1 *l_1);

void add_at_end (ls_type_1 **list, char *str);

void reverst_linked_list (ls_type_1 **off);

// chained list

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

List *addend(int nbr, int total, List *enda);
