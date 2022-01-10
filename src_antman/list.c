/*
** EPITECH PROJECT, 2021
** list
** File description:
** list.c
*/

#include "my.h"
#include "am_header.h"


static Cell *createcell(int nbr, int total)
{
    Cell *cell = malloc(sizeof(Cell));
    if(!cell)
        return NULL;
    cell->nbr = nbr;
    cell->total = total;
    cell->next = NULL;
    cell->prev = NULL;
    return cell;
}

List *emptylist(void)
{
    return NULL;
}

int isemptylist(List *L)
{
    return L == NULL;
}

void printlist(List *L)
{
    while(!isemptylist(L)) {
        if(L->total != 1){
            my_putstr("@");
             my_putstr("@");
            my_putunsint(L->nbr);
            my_putstr("@");
            my_putunsint(L->total);
        }
        else{
            my_putstr("@");
            my_putunsint(L->nbr);   
        }
        L = L->next;
    }
}

List *freelist(List *L)
{
    List *tmp = NULL;
    while (L) {
        tmp = L->next;
        free(L);
        L = tmp;
    }
    return L;    
}

int getat(List *L, int pos)
{
    int i = 0;
        if(isemptylist(L)) {
            my_putstr("Liste vide\n");
            return -1;
        }
    while (i < pos) {
        L = L->next;
        i++;
    }
    return L->nbr;
}

int lenlist(List *L)
{
    long len = 0;
    while (L) {
        L = L->next;
        len++; 
    }
    return len;
}

void setat(List *L, int pos, int nbr, int total)
{
    int i = 0;
    if (isemptylist(L)) {
        return;
    }
    while(i < pos ) {
        i++;
        L = L->next;
    }
    L->nbr = nbr;
     L->total = total;
}

List *freeat(List *L, int pos)
{
    List *tmp = NULL;
    List *prec = L;
    List *cur = L;
    int i = 0;
    if (pos == 0){
        L = L->next;
        free(cur);
        return L;
    }
    while(i < pos ) {
        i++;
        prec = cur;
        cur = cur->next;   
    }
    prec->next = cur->next;
    free(cur);
    return L;    
}

List *addat(List *L, int nbr, int total, int pos)
{
    List *prec = L;
    List *cur = L;
    int i = 0;
    Cell *cell = createcell(nbr, total);
    if(isemptylist(L))
        return cell;
    if(pos == 0) {
        cell->next = L;
        L->prev = cell;
        return cell;
    }
    while(i < pos ) {
        prec = cur;
        cur = cur->next;
        i++;
    }
    prec->next = cell;
    cell->prev = prec;
    cell->next = cur;
    return L;
}

List *addend(int nbr, int total, List *enda)
{

    Cell *cell = createcell(nbr, total);
    cell->next = NULL;
    cell->prev = enda;
    enda->next = cell;
    enda = cell;
    return enda;
}


