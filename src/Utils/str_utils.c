/*
** EPITECH PROJECT, 2025
** str_utils
** File description:
** we like strings
*/
#include <unistd.h>
#include <stdlib.h>
#include "../../includes/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
}

int my_strlen(char *str)
{
    int total = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        total++;
    }
    return total;
}

char *my_strdup(char *src)
{
    int len_src = my_strlen(src);
    char *my_ptr = malloc(sizeof(char) * len_src + 1);
    int i = 0;

    for (i = 0; i != len_src; i++) {
        my_ptr[i] = src[i];
    }
    my_ptr[i] = '\0';
    return my_ptr;
}

static char **fill_array(char **array, char **my_new_array, int i,
    int nb_lines_to_add)
{
    int tmp = 0;
    int gap = 0;

    while (array[tmp] != NULL && tmp < i + nb_lines_to_add) {
        if (array[tmp] != NULL) {
            my_new_array[tmp] = my_strdup(array[tmp + gap]);
        } else {
            gap++;
        }
        tmp++;
    }
    while (tmp < i + nb_lines_to_add) {
        my_new_array[tmp] = NULL;
        tmp++;
    }
    my_new_array[tmp] = NULL;
    return my_new_array;
}

char **my_array_dup(char **array, int nb_lines_to_add)
{
    int i = 0;
    char **my_new_array = NULL;

    while (array[i] != NULL) {
        i++;
    }
    my_new_array = malloc(sizeof(char *) * (i + nb_lines_to_add + 1));
    my_new_array[i + nb_lines_to_add] = NULL;
    return fill_array(array, my_new_array, i, nb_lines_to_add);
}
