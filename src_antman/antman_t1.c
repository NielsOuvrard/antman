/*
** EPITECH PROJECT, 2022
** antman_t1.c
** File description:
** type 1
*/

#include "my.h"
#include "am_header.h"

char **str_to_array (char *str)
{
    int k = 0, size, i_map = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' )
            k++;
        else if (str[i] == '\n')
            k += 2;
    }
    char **map = malloc(sizeof(char *) * (k + 2));
    for (int i = 0; str[i] != '\0'; i++) {
        for (size = 0; str[i + size] != '\0' && str[i + size] != ' ' && str[i + size] != '\n'; size++);
        map[i_map] = malloc(sizeof(char) * (size + 1));
        my_memset(map[i_map], size + 1, '\0');
        for (int j = 0; j < size; j++)
            map[i_map][j] = str[i + j];
        // my_printf("elem %d : %s\n", i_map, map[i_map]);
        i_map++;
        if (str[i + size] == '\0')
            i--;
        if (str[i + size] == '\n') {
            map[i_map] = malloc(sizeof(char) * (2));
            my_memset(map[i_map], 2, '\0');
            map[i_map][0] = '\n';
            i_map++;
        }
        i += size;
    }
    map[i_map] = NULL;
    return map;
}

int *delet_the_value (int *array, int value)
{
    int index;
    for (index = 1; array[index] != value && index < array[0]; index++);
    while (index + 1 < array[0]) {
        array[index] = array[index + 1];
        index++;
    }
    array[0] -= 1;
    return array;
}

int *check_the_same (char **map)
{
    int len_arr = my_arraylen(map);
    int *arr_elems = malloc(sizeof(int) * (len_arr + 1));
    arr_elems[0] = len_arr + 1;
    for (int i = 0; i < len_arr; i++)
        arr_elems[i + 1] = i;
    for (int i = 1; arr_elems[0] > i; i++) {
        char *tmp = map[arr_elems[i]];
        int elems = 0;
        for (int j = i + 1; arr_elems[0] > j; j++) {
            // my_printf("%s -> %d,\t %s -> %d\tsize %d\n", tmp, arr_elems[i], map[arr_elems[j]], arr_elems[j], arr_elems[0]);
            if (!my_strcmp(tmp, map[arr_elems[j]])) {
                delet_the_value(arr_elems, arr_elems[j]);
                elems++;
                j--;
            }                /// C1
        }
    }
    return arr_elems;
}

char *array_int_to_str (char **map, int *array_int, char *file)
{
    int size = my_strlen(file) + 1;
    char *compressed = malloc(sizeof(char) * size * 5);
    my_memset(compressed, size, '\0');
    for (int i = 1; i < array_int[0]; i++) {
        my_strcat(compressed, map[array_int[i]]);
        my_strcat(compressed, "@");
    }
    // my_printf("str : %s\n", compressed);
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 1; j < array_int[0]; j++) {
            if (!my_strcmp(map[array_int[j]], map[i])) {                /// C1
                char *str_j = my_int_to_str(j);
                my_strcat(compressed, str_j);
                free(str_j);
                char *virgule = malloc(sizeof(char) * 2);
                my_strcpy(virgule, ",");
                my_strcat(compressed, virgule);
                free(virgule);
            }
        }
    }
    return compressed;
}

int type_1 (char *file)
{
    char **map = str_to_array(file);
    // dump_array_str(map);
    int *arr_int = check_the_same(map);
    // dump_arr_int(arr_int);
    // dump_arr_int_str(map, arr_int);
    char *compressed = array_int_to_str(map, arr_int, file);

    my_putstr(compressed);      // write into file
    my_putchar('\n');

    free(compressed);
    free(arr_int);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    return 0;
}
