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
        int a = 0;
        char *tmp = malloc(sizeof(char) * (size + 1));
        my_memset(tmp, size + 1, '\0');
        if (str[i + size] == '\n')
            a = 2;
        else if (str[i + size] == ' ')
            a = 1;
        for (int j = 0; j < size; j++)
            tmp[j] = str[i + j];
        my_put_in_list(&list, tmp, a);
        if (str[i + size] == '\0')
            i++;
        // if (str[i + size] == '\n') {
        //     char *tmp2 = malloc(sizeof(char) * 2);
        //     my_memset(tmp2, 2, '\0');
        //     tmp2[0] = '\n';
        //     my_put_in_list(&list, tmp2);
        // }
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

int exist_in_list (ls_type_1 *list, char *s)
{
    int i = 0;
    while (list) {
        if (my_strlen(s) == my_strlen(list->str) && !my_strcmp(s, list->str))
            return i;
        i++;
        list = list->next;
    }
    return 0;
}

void check_the_same (ls_type_1 *list)
{
    ls_type_1 *explore = list;
    ls_type_1 *alone = NULL;
    while (explore) {
        if (!exist_in_list(alone, explore->str)) {
            my_put_in_list(&alone, explore->str, explore->a);
        }
        explore = explore->next;
    }
    reverst_linked_list(&alone);
    ls_type_1 *dico = alone;
    while (dico) {
        my_putstr(dico->str);
        my_putstr("@");
        dico = dico->next;
    }
    my_putchar('|');
    while (list) {
        my_putint(exist_in_list(alone, list->str));
        if (list->a == 1)
            my_putchar('|');
        else if (list->a == 2)
            my_putchar('^');
        else
            my_putchar('?');
        list = list->next;
    }
    return;
}

//////////////////////// OPTI MIN /////////////////////////////////////////////

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
    int size = 0, map_i = 0, map_i_size = my_strlen(list->str);
    // i = decalage du premier str ckeck
    // same = nombre de mots que l'on compare avec le reste
    // dec = check str par str pour le same
    int nmb_occurences = 0;
    for (int dec = 0; how_far_list(list, dec + same) != NULL; dec++)
        nmb_occurences += some_str_are_same(list, same, dec);
    for (int  k = 0; size_strlist != NULL && k < same; k++) {
        size += my_strlen(size_strlist->str);
        size_strlist = size_strlist->next;
    }
    while (next_list != NULL) {
        if (!my_strcmp(list->str, next_list->str))
            map_i++;
        next_list = next_list->next;
    }
    // my_printf("Ok jusqu'ici \n");
    if (nmb_occurences) {
        if (map_i * map_i_size > nmb_occurences * size) {
            valeures.opti = map_i * map_i_size;
            valeures.same = 1;
        } else {
            valeures.opti = nmb_occurences * size;
        }
        // my_printf("size : %d\t", size);
        // my_printf("occurences : %d   \t", nmb_occurences);
        // my_putint(nmb_occurences * size);
        // my_putchar('\t');
        // my_putint(map_i * map_i_size);
        // my_putchar('\n');
    }
    return valeures;
}

int are_same (ls_type_1 *off, ls_type_1 *explore, type_1_opt val)
{
    int tmp = 0;
    for (int same = 0; same < val.same && how_far_list(explore, same) != NULL; same++)
        if (!my_strcmp(how_far_list(off, same), how_far_list(explore, same)))
            tmp++;
    if (tmp != val.same)
        return 0;
    return 1;
}

void concat_first_elems (ls_type_1 *list)
{
    if (list == NULL || list->next == NULL)
        return;
    int size = my_strlen(list->str) + my_strlen(list->next->str) + 2;
    char *final_v = malloc(sizeof(char) * size);
    my_memset(final_v, size, '\0');
    my_strcpy(final_v, list->str);
    my_strcat(final_v, " ");
    my_strcat(final_v, list->next->str);
    free(list->str);
    free(list->next->str);
    list->str = final_v;
    ls_type_1 *to_free = list->next;
    list->next = to_free->next;
    free(to_free);
    return;
}

int concat_list (ls_type_1 *list, int size)
{
    for (int i = 0; i < size && list->next != NULL; i++)
        concat_first_elems(list);
    return 0;
}

int check_some_same (ls_type_1 *off)
{
    ls_type_1 *list = off;
    type_1_opt val;
    val.opti = 0;
    for (int i = 0; list != NULL; i++) {
        for (int same = 2; how_far_list(list, same - 1) != NULL && how_far_list(list, same) != NULL; same++) {
            type_1_opt tmp = some_same(list, same, i);
            val = tmp.opti > val.opti ? tmp : val;
        }
        list = list->next;
    }
    if (val.same == 1)
        return 0;
    // my_printf("\nmeilleur optimisation :\n");
    // my_printf("chars optimisés : %d\n", val.opti);
    // my_printf("position dans la liste : %d\n", val.i);
    // my_printf("longueur : %d\n", val.same);
    for (int q = 0; q < val.i; q++)
        off = off->next;
    ls_type_1 *explore = off;
    for (int q = 0; q < val.same + 1; q++)
        explore = explore->next;
    int index = val.i + val.same;
    for (int i = val.i; explore != NULL; i++) {
        if (!my_strcmp(off->str, explore->str) && are_same(off, explore, val))
            concat_list(explore, val.same - 1);
        explore = explore->next;
    }
    concat_list(off, val.same - 1);
    return 1;
}

int type_1 (char *file)
{
    ls_type_1 *list = str_to_file(file);
    if (my_list_size(list) < 500)
        while (check_some_same(list));
    check_the_same(list);
    my_putchar('\n');
    free_linked_list_am(list);
    return 0;
}
