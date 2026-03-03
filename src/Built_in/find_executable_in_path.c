/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** Make your own shell.
*/

#include <stdlib.h>
#include <string.h>
#include "../../includes/my.h"

char *find_executible_in_path(char **my_args, char *env_path)
{
    char *test_path = my_strdup(env_path);
    char *exec_path = NULL;

    test_path = strtok(test_path, "=:");
    while (test_path != NULL) {
        exec_path = malloc(sizeof(char) * my_strlen(test_path) +
            my_strlen(my_args[0]) + 2);
        exec_path[0] = '\0';
        exec_path = my_strcat(exec_path, test_path);
        exec_path = my_strcat(exec_path, "/");
        exec_path = my_strcat(exec_path, my_args[0]);
        if (check_if_file_exist(exec_path) == 1) {
            return exec_path;
        }
        free(exec_path);
        test_path = strtok(NULL, "=:");
    }
    return NULL;
}

char *get_command_location(char **my_args, char **my_env)
{
    int i = 0;

    while (my_env[i] != NULL) {
        if (my_env[i][0] == 'P' && my_env[i][1] == 'A' && my_env[i][3] == 'H') {
            return find_executible_in_path(my_args, my_env[i]);
        }
        i++;
    }
    return "/bin/";
}
