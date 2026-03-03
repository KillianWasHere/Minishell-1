/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** Make your own shell.
*/

#include "../../includes/my.h"
#include "../../includes/env_struct.h"

void get_used_built_in(char **my_args, env_struct_t *data)
{
    if (my_strcmp(my_args[0], "cd") == 0)
        cd_built_in(data, my_args);
    if (my_strcmp(my_args[0], "env") == 0)
        display_env(data->my_env);
    if (my_strcmp(my_args[0], "setenv") == 0)
        get_env_to_add(my_args, data);
    if (my_strcmp(my_args[0], "unsetenv") == 0)
        get_env_to_rm(my_args, data);
}
