/*
** EPITECH PROJECT, 2025
** project name
** File description:
** its a project
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "../includes/my.h"
#include "../includes/env_struct.h"

void write_error(char *command)
{
    my_putstr(command);
    my_putstr(": Command not found.\n");
}

int shell(char **env, env_struct_t *data)
{
    char *line = NULL;
    char **my_args = NULL;
    size_t len = 0;

    my_putstr("$> ");
    getline(&line, &len, stdin);
    while (my_strcmp("exit\n", line) != 0) {
        my_args = get_words(line);
        check_space_tab(my_args);
        if (check_built_in(my_args, env, data) == 768)
            write_error(my_args[0]);
        my_putstr("$> ");
        getline(&line, &len, stdin);
        free_my_array(my_args);
    }
    my_putstr("exit\n");
    free(line);
    free_my_array(data->my_env);
    free(data);
    return 0;
}

int main(__attribute__((unused)) int argc, __attribute__((unused))
    char *argv[], char **env)
{
    env_struct_t *data = malloc(sizeof(env_struct_t));

    data->my_env = my_array_dup(env, 0);
    data->og_env = env;
    if (!isatty(0))
        return tty_shell(env, data);
    return shell(env, data);
}
