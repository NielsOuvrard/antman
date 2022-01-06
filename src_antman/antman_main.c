/*
** EPITECH PROJECT, 2022
** antman_main.c
** File description:
** le main du antman tu connais
*/

#include "my.h"
#include "am_header.h"
#include "both_header.h"

void dump_arr_int (int *arr)
{
    for (int i = 1; i < arr[0]; i++) {
        my_putint(arr[i]);
        my_putchar('\n');
    }
    my_putchar('\n');
}

int *delet_the_value (int *array, int value)
{
    if (value > array[0]) {
        my_putstr("erreur delet_the_value\n");
        return array;
    }
    array[0] -= 1;
    int index = 1;
    for (index = 1; array[index] != value && index < array[0]; index++);
    while (index < array[0]) {
        array[index] = array[index + 1];
        index++;
    }
    return array;
}

int *check_the_same (char **map)
{
    int len_arr = my_arraylen(map);
    int *arr_elems = malloc(sizeof(int) * (len_arr + 1));
    arr_elems[0] = len_arr;
    for (int i = 0; i < len_arr; i++)
        arr_elems[i + 1] = i;
    for (int i = 0; arr_elems[0] > i; i++) {
        char *tmp = map[i];
        for (int j = i + 1; arr_elems[0] > j; j++)
            if (!my_strcmp(tmp, map[j]))                /// C1
                delet_the_value(arr_elems, j);
    }
    return arr_elems;
}

char *array_int_to_str (char **map, int *array_int, char *file)
{
    int size = my_strlen(file) + 1;
    char *compressed = malloc(sizeof(char) * size);
    my_memset(compressed, size, '\0');
    for (int i = 1; i < array_int[0]; i++) {
        my_strcat(compressed, map[array_int[i]]);
        my_strcat(compressed, "@");
    }
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 1; j < array_int[0]; j++) {
            if (!my_strcmp(map[array_int[j]], map[i])) {                /// C1
                char *tmp = malloc(sizeof(char) * 2);
                tmp[0] = ITOC(j);
                tmp[1] = '\0';
                my_strcat(compressed, tmp);
                free(tmp);
            }
        }
    }
    return compressed;
}

int antman (char *file)
{
    char **map = str_to_array(file);
    int *arr_int = check_the_same(map);
    char *compressed = array_int_to_str(map, arr_int, file);

    my_putstr(compressed);
    my_putchar('\n');

    free(compressed);
    free(file);
    free(arr_int);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    return 0;
}

int main (int ac, char **av)
{
    char *file = file_to_str(av[1]);
    if (file == NULL)
        return 84;
    antman(file);
    return 0;
}
