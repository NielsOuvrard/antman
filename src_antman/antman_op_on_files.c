/*
** EPITECH PROJECT, 2022
** antman_op_on_files.c
** File description:
** operations on files
*/

#include "my.h"
#include "am_header.h"

char *file_to_str (char *file_name, int *size)
{
    int file = open(file_name, O_RDONLY);
    if (file <= 0)
        return NULL;
    int a, size_read, nmb_rows;
    struct stat *buf;
    buf = malloc(sizeof(struct stat));
    if(stat(file_name, buf) == -1)
        return NULL;
    (*size) = buf->st_size;
    free(buf);
    char *buffer = malloc(sizeof(char) * ((*size) + 1));
    size_read = read(file, buffer, (*size));
    if (size_read <= 0)
        return NULL;
    buffer[(*size)] = '\0';
    close(file);
    return buffer;
}
