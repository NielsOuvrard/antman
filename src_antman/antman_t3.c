/*
** EPITECH PROJECT, 2022
** antman_t2.c
** File description:
** type 2
*/

#include "my.h"
#include "am_header.h"

int get_nbr(char *yes, int i)
{
    int res = 0, x = i, neg = 1;
    while (yes[x] <= 57 && yes[x] >= 48) {
    res = res * 10;
    res = res + (yes[x] - 48);
    x++;
    }
    return res;
}

int len_line(char *file, int i) {

    int w = 0, res = 0, e = 0;

    for(e = 0; file[e] != '\0' && w < i; e++) {
        if (file[e] == '\n')
            w++;
    }
    while (file[e] != '\n') {
        e++;
        res++;
    }
    res++;
    return res;
}


int find_start(char *file) {
    int e = 1, res = len_line(file, 0);
    while(len_line(file, e) > 4) {
        res = res + len_line(file, e);
        e++;
    }
    return res;
}

int nbn(char *file, int start) {
    int res = 0;
    while(file[start] != '\0'){
        if(file[start] == '\n')
            res++;
        start++;
    }

    return res - 1;
}

void size(char *file, List **list, List **enda) {

    int a = 0, i = find_start(file), res = 0, temp1, temp2, tot = 1, nb = nbn(file, find_start(file));

    for(int w = 0; w < i; w++) {
        if(file[w] == '\n' /*&& w != i - 1*/)
            my_putchar('@');
        else if (file[w] != '\n')
            my_putchar(file[w]);
    }

    for(int w = 0; w < nb; w++) {
        temp1 = get_nbr(file, i);
        while (file[i] != '\n' && file[i] != '\0')
            i++;
        i++;
        temp2 = get_nbr(file, i);
        if(temp1 == temp2)
            tot++;
        if(temp1 != temp2) {
            addend(temp1, tot, enda, list);
            tot = 1;
            a++;
        }
    }
    temp1 = get_nbr(file, i);
    *list = addat(*list, temp1, tot, a);
}

int type_3 (char *file)
{
    List *list = emptylist();
    List *enda = NULL;
    size(file, &list, &enda);
    printlist(list);
    return 0;
}
