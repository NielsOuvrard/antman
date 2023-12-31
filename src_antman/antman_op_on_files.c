/*
** EPITECH PROJECT, 2022
** antman_op_on_files.c
** File description:
** operations on files
*/

#include "my.h"
#include "am_header.h"

int stat_size (char *file_name, int *error)
{
    int size;
    struct stat *buf;
    buf = malloc(sizeof(struct stat));
    if (stat(file_name, buf) == -1) {
        (*error) = 84;
        return -1;
    }
    size = buf->st_size;
    free(buf);
    return size;
}

char *file_to_str (char *file_name, int *size, int *error)
{
    int file = open(file_name, O_RDONLY);
    int a, size_read, nmb_rows;
    if (((*size) = stat_size(file_name, error)) == -1)
        return NULL;
    char *buffer = malloc(sizeof(char) * ((*size) + 1));
    if (buffer == NULL) {
        (*error) = 84;
        return NULL;
    }
    size_read = read(file, buffer, (*size));
    if (size_read == 0) {
        return NULL;
    } else if (size_read < 0) {
        (*error) = 84;
        return NULL;
    }
    buffer[(*size)] = '\0';
    close(file);
    return buffer;
}
