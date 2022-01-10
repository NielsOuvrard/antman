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
        if (file[e] == '@')
            w++;
    }
    while (file[e] != '@') {
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

void gigi(char *file) {
    
    int i = find_start(file), e = 0, temp = 0, nb = 0;

    for(int x = 0; x < i; x++) {
        if(file[x] == '@')
            my_putchar('\n');
        else    
            my_putchar(file[x]);
    }
    for (i ; file[i] != '\0'; i) {
        if (file[i+1] != '@') {
            i++;
            while(file[i] != '@' && file[i] != '\0') {
                my_putchar(file[i]);
                i++;
            }
            my_putchar('\n');
        }
        if (file[i+1] == '@') {
            i = i + 2;
            temp = get_nbr(file, i);
            while(file[i] != '@')
                i++;
            i++;
            nb = get_nbr(file, i);
            for(int count = 0; count < nb ;count++) {
                my_putunsint(temp);
                my_putchar('\n');
            while(file[i] != '@'  && file[i] != '\0')
                i++;
            }
        }
    }


}


int type_3 (char *file)
{
    gigi(file);

    return 0;
}
