/*
** EPITECH PROJECT, 2021
** my_strcmp.c
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1 , char const *s2)
{
    int india = 0;
    int juliette = 0;
    unsigned int value;

    while (s2[juliette] != '\0') {
        juliette++;
    }
    while (s1[india] == s2[india] && india != juliette) {
        india++;
    }
    if (india == juliette)
        return 0;
    value = s1[india] - s2[india];
    return (value);
}
