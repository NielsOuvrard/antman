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

int nbn(char *file) {
    int i = 0, res = 0;
    while(file[i] != '\0'){
        if(file[i] == '\n')
            res++;
        i++;
    }
    return res;
}

void size(char *file, List **list) {

    int a = 0, i = 0, res = 0, temp1, temp2, tot = 1, nb = nbn(file)-1;

    for(int w = 0; w < nb; w++) {
        temp1 = get_nbr(file, i);
        while (file[i] != '\n' && file[i] != '\0')
            i++;
        i++;
        temp2 = get_nbr(file, i);
        if(temp1 == temp2)
            tot++;
        if(temp1 != temp2) {
            *list = addat(*list, temp1, tot, 0);
            tot = 1;
            a++;
        }
    }
    *list = addat(*list, temp1, tot, a);
}

int type_2 (char *file)
{
    List *list = emptylist();
    size(file, &list);
    printlist(list);
    //my_putunsint(size(file));
    //my_putstr(file);
    //my_putunsint(size(file));
    //my_putstr(file);

    return 0;
}
