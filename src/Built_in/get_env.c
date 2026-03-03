/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** Make your own shell.
*/

#include <stdlib.h>
#include <string.h>
#include "../../includes/my.h"
#include "../../includes/env_struct.h"

char *get_env_line_as_char(char *to_find, env_struct_t *data)
{
    int i = 0;
    char *tmp = NULL;

    while (data->my_env[i] != NULL) {
        tmp = my_strdup(data->my_env[i]);
        tmp = strtok(tmp, "=");
        if (my_strcmp(tmp, to_find) == 0) {
            free(tmp);
            return my_strdup(data->my_env[i]);
        }
        free(tmp);
        i++;
    }
    return NULL;
}

int get_env_line_as_int(char *to_find, env_struct_t *data)
{
    int i = 0;
    char *tmp = NULL;

    while (data->my_env[i] != NULL) {
        tmp = my_strdup(data->my_env[i]);
        tmp = strtok(tmp, "=");
        if (my_strcmp(tmp, to_find) == 0) {
            free(tmp);
            return i;
        }
        free(tmp);
        i++;
    }
    return -1;
}
