/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** first part of the 42sh project
*/
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "../includes/my.h"
#include "../includes/env_struct.h"

int check_if_file_exist(char *my_args)
{
    struct stat sb;

    if (stat(my_args, &sb) == -1)
        return 0;
    return 1;
}

char *init_command(char **my_args, env_struct_t *data)
{
    char *my_command = NULL;
    char *command_location = NULL;

    if (my_args[0][0] == '.' || my_args[0][0] == '/' ||
        check_if_file_exist(my_args[0]) == 1) {
        my_command = malloc(sizeof(char) * my_strlen(my_args[0]) + 1);
        my_command[0] = '\0';
        my_command = my_strcat(my_command, my_args[0]);
        return my_command;
    } else {
        command_location = get_command_location(my_args, data->my_env);
        if (command_location == NULL)
            return NULL;
        my_command = malloc(sizeof(char) * my_strlen(command_location) + 1);
        my_command[0] = '\0';
        my_command = my_strcat(my_command, command_location);
        free(command_location);
        return my_command;
    }
    return NULL;
}

int my_exec(char **my_args, char **env, env_struct_t *data)
{
    pid_t pid = fork();
    int status;
    char *my_command = NULL;

    if (pid == 0) {
        my_command = init_command(my_args, data);
        if (my_command == NULL)
            exit(3);
        if (execve(my_command, my_args, env) == -1) {
            free(my_command);
            free_my_array(my_args);
            exit(84);
        }
        exit(0);
    }
    waitpid(pid, &status, 0);
    display_exit_error(status);
    free(my_command);
    return status;
}

int check_built_in(char **my_args, char **env, env_struct_t *data)
{
    if (my_strcmp(my_args[0], "cd") == 0
        || my_strcmp(my_args[0], "env") == 0
        || my_strcmp(my_args[0], "setenv") == 0
        || my_strcmp(my_args[0], "unsetenv") == 0) {
        get_used_built_in(my_args, data);
        return 0;
    }
    return my_exec(my_args, env, data);
}
