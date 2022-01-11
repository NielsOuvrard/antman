/*
** EPITECH PROJECT, 2022
** antman_t1.c
** File description:
** type 1
*/

#include "my.h"
#include "am_header.h"

char *how_far_list (ls_type_1 *list, int far)
{
    while (list != NULL && far > 0) {
        list = list->next;
        far--;
    }
    if (list == NULL)
        return NULL;
    return list->str;
}

ls_type_1 *str_to_file (char *str)
{
    int k = 0, size, i_map = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' )
            k++;
        else if (str[i] == '\n')
            k += 2;
    }
    ls_type_1 *list = NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        for (size = 0; str[i + size] != '\0' && str[i + size] != ' ' && str[i + size] != '\n'; size++);
        char *tmp = malloc(sizeof(char) * (size + 1));
        my_memset(tmp, size + 1, '\0');
        for (int j = 0; j < size; j++)
            tmp[j] = str[i + j];
        my_put_in_list(&list, tmp);
        if (str[i + size] == '\0')
            i++;
        if (str[i + size] == '\n') {
            char *tmp2 = malloc(sizeof(char) * (2));
            my_memset(tmp2, 2, '\0');
            tmp2[0] = '\n';
            my_put_in_list(&list, tmp2);
        }
        i += size;
    }
    reverst_linked_list(&list);
    return list;
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

int *check_the_same (ls_type_1 *list)
{
    int len_arr = my_list_size(list);
    int *arr_elems = malloc(sizeof(int) * (len_arr + 1));
    arr_elems[0] = len_arr + 1;
    for (int i = 0; i < len_arr; i++)
        arr_elems[i + 1] = i;
    ls_type_1 *explore = list;
    for (int i = 1; arr_elems[0] > i; i++) {
        int elems = 0;
        for (int j = i + 1; arr_elems[0] > j; j++) {
            if (!my_strcmp(explore->str, how_far_list(list, arr_elems[j]))) {
                delet_the_value(arr_elems, arr_elems[j]);
                elems++;
                j--;
            }
        }
        explore = explore->next;
    }
    return arr_elems;
}

void array_int_to_str (ls_type_1 *list, int *array_int, char *file)
{
    for (int i = 1; i < array_int[0]; i++) {
        my_putstr(how_far_list(list, array_int[i]));
        my_putstr("@");
    }
    ls_type_1 *explore = list;
    for (int i = 0; explore != NULL; i++) {
        for (int j = 1; j < array_int[0]; j++) {
            if (!my_strcmp(how_far_list(list, array_int[j]), explore->str)) {                /// C1
                my_putint(j);
                my_putchar('|');
            }
        }
        explore = explore->next;
    }
    return;
}

//////////////////////// OPTI MIN ////////////////////




// int check_some_same (char **map)
// {
//     type_1_opt val;
//     val.opti = 0;
//     for (int i = 0; map[i] != NULL; i++) { // map[i] != NULL
//         for (int same = 2; map[i + same - 1] != NULL && map[i + same] != NULL; same++) { //
//             type_1_opt tmp = some_same(map, same, i);
//             val.opti = tmp.opti > val.opti ? tmp.opti : val.opti;
//         }
//     }
//     my_printf("max opti : %d\n", val.opti);
//     for (int i = val.i; map[i] != NULL; i++) {
//         int tmp = 0;
//         for (int same = 0; same < val.same && map[i + same] != NULL; same++)
//             if (!my_strcmp(map[i], map[i + same]))
//                 tmp++;
//         if (tmp == val.same) {
//             /// my_strcat(map[i], map[i + 1]);
//         }
//     }
//     return 0;
// }

// type_1_opt some_same (char **map, int same, int i)
// {
//     type_1_opt valeures;
//     valeures.i = i;
//     valeures.same = same;
//     valeures.opti = 0;
//     int size = 0, map_i = 0, map_i_size = my_strlen(map[i]);
//     // i = decalage du premier str ckeck
//     // same = nombre de mots que l'on compare avec le reste
//     // dec = check str par str pour le same
//     int nmb_occurences = 0;
//     for (int dec = 0; map[i + dec + same] != NULL; dec++)
//         nmb_occurences += some_str_are_same(map, i, same, dec);
//     for (int f = 1; f < same; f++)
//         size += my_strlen(map[i + f]);
//     size += map_i_size;
//     for (int f = 1; map[i + f] != NULL; f++)
//         if (!my_strcmp(map[i], map[i + f]))
//             map_i++;
//     if (nmb_occurences) {
//         if (map_i * map_i_size > nmb_occurences * size)
//             valeures.opti = map_i * map_i_size;
//         else
//             valeures.opti = nmb_occurences * size;
//     }
//     return valeures;
// }


int some_str_are_same (ls_type_1 *list, int same, int dec)
{
    for (int k = 0; same > k; k++) {
        if (how_far_list(list, k + same + dec) == NULL)
            return 0;
        if (my_strcmp(how_far_list(list, k), how_far_list(list, k + same + dec)))
            return 0;
    }
    return 1;
}

type_1_opt some_same (ls_type_1 *list, int same, int i)
{
    ls_type_1 *size_strlist = list;
    ls_type_1 *next_list = list->next;
    type_1_opt valeures;
    valeures.i = i;
    valeures.same = same;
    valeures.opti = 0;
    return valeures;
    int size = 0, map_i = 0, map_i_size = my_strlen(list->str);
    // i = decalage du premier str ckeck
    // same = nombre de mots que l'on compare avec le reste
    // dec = check str par str pour le same
    int nmb_occurences = 0;
    for (int dec = 0; how_far_list(list, dec + same) != NULL; dec++)
        nmb_occurences += some_str_are_same(list, same, dec);
    while (size_strlist != NULL) {
        size += my_strlen(size_strlist->str);
        size_strlist = size_strlist->next;
    }
    while (next_list != NULL) {
        if (!my_strcmp(list->str, next_list->str))
            map_i++;
        next_list = next_list->next;
    }
    if (nmb_occurences) {
        if (map_i * map_i_size > nmb_occurences * size)
            valeures.opti = map_i * map_i_size;
        else
            valeures.opti = nmb_occurences * size;
        my_printf("size : %d\n", size);
        my_printf("occurences : %d\n", nmb_occurences);
        my_putint(nmb_occurences * size);
        my_putchar('\n');
        my_putint(map_i * map_i_size);
        my_putchar('\n');
        my_putchar('\n');
    }
    return valeures;
}

int check_some_same (ls_type_1 *off)
{
    ls_type_1 *list = off;
    ls_type_1 *explore = off;
    type_1_opt val;
    val.opti = 0;
    for (int i = 0; explore != NULL; i++) {
        for (int same = 2; how_far_list(list, same - 1) != NULL && how_far_list(list, same) != NULL; same++) {
            type_1_opt tmp = some_same(list, same, i);
            my_printf("tmp : %s\n", tmp);
            val.opti = tmp.opti > val.opti ? tmp.opti : val.opti;
        }
        explore = explore->next;
    }
    my_printf("max opti : %d\n", val.opti);
    // for (int i = val.i; map[i] != NULL; i++) {
    //     int tmp = 0;
    //     for (int same = 0; same < val.same && map[i + same] != NULL; same++)
    //         if (!my_strcmp(map[i], map[i + same]))
    //             tmp++;
    //     if (tmp == val.same) {
    //         /// my_strcat(map[i], map[i + 1]);
    //     }
    // }
    return 0;
}

int type_1 (char *file)
{
    ls_type_1 *list = str_to_file(file);
    // int *arr = check_the_same(list);
    // array_int_to_str(list, arr, file);
    // free(arr);

    check_some_same(list);

    // disp_linked_list_am(list);
    // dump_arr_int(arr);
    // dump_arr_int_str(map, arr_int);

    my_putchar('\n');
    free_linked_list_am(list);
    return 0;
}
