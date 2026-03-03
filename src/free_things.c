/*
** EPITECH PROJECT, 2025
** project name
** File description:
** its a project
*/
#include <stdlib.h>
#include "../includes/my.h"

void free_my_array(char **my_args)
{
    int i = 0;

    while (my_args[i] != NULL) {
        free(my_args[i]);
        i++;
    }
    free(my_args);
}
