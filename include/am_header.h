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
