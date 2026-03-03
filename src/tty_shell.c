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

int execute_command(char **env, env_struct_t *data, char *line)
{
    int status = 0;
    char **my_args = NULL;

    my_args = get_words(line);
    check_space_tab(my_args);
    status = check_built_in(my_args, env, data);
    if (status == 768)
        write_error(my_args[0]);
    free_my_array(my_args);
    return status;
}

int tty_shell(char **env, env_struct_t *data)
{
    size_t len = 0;
    char *line = NULL;
    char *previous_line = NULL;
    int status = 0;

    getline(&line, &len, stdin);
    while (line != NULL) {
        status = execute_command(env, data, line);
        previous_line = my_strdup(line);
        getline(&line, &len, stdin);
        if (my_strcmp(line, previous_line) == 0) {
            free(previous_line);
            break;
        }
        free(previous_line);
    }
    free(line);
    free(data);
    exit(status);
}
