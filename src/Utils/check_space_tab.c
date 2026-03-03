/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** Make your own shell.
*/
#include <stdlib.h>
#include <stdio.h>
#include "../../includes/my.h"
#include "../../includes/env_struct.h"

void replace_tab(char **my_args, int i)
{
    char *tmp = NULL;

    tmp = malloc(sizeof(char) * my_strlen(my_args[0]) - i + 1);
    tmp[0] = '\0';
    my_strcat(tmp, &my_args[0][i]);
    free(my_args[0]);
    my_args[0] = malloc(sizeof(char) * my_strlen(tmp) + 1);
    my_args[0][0] = '\0';
    my_strcat(my_args[0], tmp);
    free(tmp);
    return;
}

void check_space_tab(char **my_args)
{
    int i = 0;

    if (my_args[0][0] == '\t') {
        while (my_args[0][i] == '\t') {
            i++;
        }
        replace_tab(my_args, i);
        return;
    }
    while (my_args[i] != NULL) {
        if (my_strlen(my_args[i]) == 0) {
            free(my_args[i]);
            my_args[i] = NULL;
            return;
        }
        i++;
    }
    return;
}
