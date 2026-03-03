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

static void check_if_pwd_exist(env_struct_t *data, int nb_l, char *line_edit,
    char **my_args)
{
    if (my_args[1][0] == 'P' || my_args[1][2] == '=') {
        free(data->my_env[nb_l]);
        data->my_env[nb_l] = malloc(sizeof(char) * my_strlen(my_args[1])
            + 1);
        data->my_env[nb_l][0] = '\0';
        data->my_env[nb_l] = my_strcat(data->my_env[nb_l], my_args[1]);
    } else {
        free(data->my_env[nb_l]);
        data->my_env[nb_l] = malloc(sizeof(char) * my_strlen(my_args[1]) +
            my_strlen(line_edit) + 2);
        data->my_env[nb_l][0] = '\0';
        data->my_env[nb_l] = my_strcat(data->my_env[nb_l], line_edit);
        data->my_env[nb_l] = my_strcat(data->my_env[nb_l], "=");
        data->my_env[nb_l] = my_strcat(data->my_env[nb_l], my_args[1]);
    }
}

void edit_env(char **my_args, int nb_l, char *line_edit,
    env_struct_t *data)
{
    if (my_args[2] != NULL) {
        data->my_env[nb_l][0] = '\0';
        data->my_env[nb_l] = my_strcat(data->my_env[nb_l], line_edit);
        data->my_env[nb_l] = my_strcat(data->my_env[nb_l], "=");
        data->my_env[nb_l] = my_strcat(data->my_env[nb_l], my_args[2]);
    } else {
        check_if_pwd_exist(data, nb_l, line_edit, my_args);
    }
    return;
}

void add_new_empty_env_line(char **my_args, env_struct_t *data)
{
    int i = 0;
    char **new_env = my_array_dup(data->my_env, 1);

    free_my_array(data->my_env);
    data->my_env = new_env;
    while (data->my_env[i] != NULL) {
        i++;
    }
    data->my_env[i] = malloc(sizeof(char) * my_strlen(my_args[1]) + 2);
    data->my_env[i][0] = '\0';
    data->my_env[i] = my_strcat(data->my_env[i], my_args[1]);
    data->my_env[i] = my_strcat(data->my_env[i], "=");
}

void add_new_env_line(char **my_args, env_struct_t *data)
{
    int i = 0;
    char **new_env = my_array_dup(data->my_env, 1);

    free_my_array(data->my_env);
    data->my_env = new_env;
    while (data->my_env[i] != NULL) {
        i++;
    }
    data->my_env[i] = malloc(sizeof(char) * my_strlen(my_args[1]) +
        my_strlen(my_args[2]) + 2);
    edit_env(my_args, i, my_args[1], data);
}

int handle_error(char **my_args, env_struct_t *data)
{
    if (my_args[1] == NULL) {
        display_env(data->my_env);
        return 1;
    }
    if (check_env_name(my_args[1]) == 1) {
        my_putstr(my_args[0]);
        my_putstr(": Variable name must contain alphanumeric characters.\n");
        return 1;
    }
    if (my_args[1] != NULL && my_args[2] == NULL) {
        add_new_empty_env_line(my_args, data);
        return 1;
    }
    if (my_args[3] != NULL) {
        my_putstr(my_args[0]);
        my_putstr(": Too many arguments.\n");
        return 1;
    }
    return 0;
}

void get_env_to_add(char **my_args, env_struct_t *data)
{
    int i = 0;
    char **work_env = data->my_env;
    char *tmp = NULL;

    if (handle_error(my_args, data) == 1)
        return;
    while (work_env[i] != NULL) {
        tmp = my_strdup(work_env[i]);
        tmp = strtok(tmp, "=");
        if (my_strcmp(tmp, my_args[1]) == 0) {
            edit_env(my_args, i, tmp, data);
            free(tmp);
            return;
        }
        free(tmp);
        i++;
    }
    add_new_env_line(my_args, data);
    return;
}
