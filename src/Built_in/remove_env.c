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

void remove_env(int nb_line,
    env_struct_t *data)
{
    char **new_env = NULL;
    char *tmp = data->my_env[nb_line];

    if (tmp)
        free(tmp);
    data->my_env[nb_line] = NULL;
    new_env = my_array_dup(data->my_env, 0);
    free_my_array(data->my_env);
    data->my_env = new_env;
    return;
}

int error_handler(char **my_args)
{
    if (my_args[1] == NULL) {
        my_putstr(my_args[0]);
        my_putstr(": Too few arguments.\n");
        return 1;
    }
    return 0;
}

void get_env_to_rm(char **my_args, env_struct_t *data)
{
    int i = 0;
    char **work_env = data->my_env;
    char *tmp = NULL;

    if (error_handler(my_args) == 1)
        return;
    while (work_env[i] != NULL) {
        tmp = my_strdup(work_env[i]);
        tmp = strtok(tmp, "=");
        if (my_strcmp(tmp, my_args[1]) == 0) {
            remove_env(i, data);
            free(tmp);
            return;
        }
        free(tmp);
        i++;
    }
    return;
}
