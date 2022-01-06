/*
** EPITECH PROJECT, 2021
** my_arraylen.c
** File description:
** lengh of string
*/

int my_arraylen (char ** world)
{
    int a = 0;

    while (world[a] != 0) {
        a++;
    }
    return (a);
}
