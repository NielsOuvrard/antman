/*
** EPITECH PROJECT, 2021
** str_cpy.c
** File description:
** copier un string
*/

char *my_strcpy (char *dest, char const *src)
{
    int i = 0;
    while (src[i])
        dest[i++] = src[i];
    dest[i] = '\0';
    return (dest);
}
/*
{
    int a = 0;
    while (dest[a] != '\0' || src[a] != '\0') {
        dest[a] = src[a];
        a++;
    }
    dest[a] = '\0';
    return dest;
}
*/
