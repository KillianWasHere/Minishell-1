/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** Make your own shell.
*/
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../../includes/env_struct.h"
#include "../../includes/my.h"

void get_absolute_path(char **my_args, char *env_line)
{
    char *abs_path = NULL;

    if (my_args[1][0] == '/')
        return;
    if (env_line[my_strlen(env_line)] == '/') {
        abs_path = malloc(sizeof(char) * my_strlen(env_line) +
            my_strlen(my_args[1]) + 1);
        abs_path[0] = '\0';
        my_strcat(abs_path, my_strdup(env_line));
        my_strcat(abs_path, my_args[1]);
    } else {
        abs_path = malloc(sizeof(char) * my_strlen(env_line) +
            my_strlen(my_args[1]) + 2);
        abs_path[0] = '\0';
        my_strcat(abs_path, env_line);
        my_strcat(abs_path, "/");
        my_strcat(abs_path, my_args[1]);
    }
    free(my_args[1]);
    my_args[1] = my_strdup(abs_path);
}

void get_previous_folder(char **my_args, char *env_line)
{
    char *inverted_str = my_revstr(my_strdup(&env_line[4]));
    int i = 0;

    while (inverted_str[i] != '/') {
        i++;
    }
    i++;
    free(my_args[1]);
    my_args[1] = malloc(sizeof(char) * my_strlen(&inverted_str[i]) + 1);
    my_args[1][0] = '\0';
    my_strcat(my_args[1], my_revstr(&inverted_str[i]));
    free(inverted_str);
}

void cd_built_in(env_struct_t *data, char **my_args)
{
    char *env_line_content = NULL;
    int nb_line_in_env = -1;

    env_line_content = get_env_line_as_char("PWD", data);
    nb_line_in_env = get_env_line_as_int("PWD", data);
    if (env_line_content == NULL || my_args[1] == NULL ||
        nb_line_in_env == -1)
        return;
    if (my_strcmp(my_args[1], ".") == 0) {
        free(env_line_content);
        return;
    }
    if (my_strcmp(my_args[1], "..") == 0)
        get_previous_folder(my_args, env_line_content);
    my_putstr(my_args[1]);
    my_putchar('\n');
    chdir(my_args[1]);
    get_absolute_path(my_args, env_line_content);
    edit_env(my_args, nb_line_in_env, "PWD", data);
    free(env_line_content);
}
