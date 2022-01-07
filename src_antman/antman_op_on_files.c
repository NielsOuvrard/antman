/*
** EPITECH PROJECT, 2022
** antman_op_on_files.c
** File description:
** operations on files
*/

#include "my.h"
#include "am_header.h"

char *file_to_str (char *file_name)
{
    int file = open(file_name, O_RDONLY);
    if (file <= 0)
        return NULL;
    int a, size, size_read, nmb_rows;
    struct stat *buf;
    buf = malloc(sizeof(struct stat));
    stat(file_name, buf);
    size = buf->st_size;
    free(buf);
    char *buffer = malloc(sizeof(char) * (size + 1));
    size_read = read(file, buffer, size);
    if (size_read <= 0)
        return NULL;
    buffer[size] = '\0';
    close(file);
    return buffer;
}

// char **str_to_array (char *str)
// {
//     int k = 0, size, i_map = 0;
//     for (int i = 0; str[i] != '\0'; i++)
//         if (str[i] == ' ')
//             k++;
//     char **map = malloc(sizeof(char *) * (k + 2));
//     for (int i = 0; str[i] != '\0'; i++) {
//         for (size = 0; str[i + size] != '\0' && str[i + size] != ' '; size++);
//         map[i_map] = malloc(sizeof(char) * (size + 1));
//         my_memset(map[i_map], size + 1, '\0');
//         for (int j = 0; j < size; j++)
//             map[i_map][j] = str[i + j];
//         i_map++;
//         if (str[i + size] == '\0')
//             i--;
//         i += size;
//     }
//     map[i_map] = NULL;
//     return map;
// }
