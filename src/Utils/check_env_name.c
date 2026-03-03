/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** Make your own shell.
*/

#include "../../includes/my.h"
#include "../../includes/env_struct.h"

int check_env_name(char *env_name)
{
    int i = 0;
    int res = 0;

    while (env_name[i] != '\0') {
        if (env_name[i] >= 48 && env_name[i] <= 57)
            res++;
        if (env_name[i] >= 65 && env_name[i] <= 90)
            res++;
        if (env_name[i] >= 97 && env_name[i] <= 122)
            res++;
        i++;
    }
    if (res == my_strlen(env_name))
        return 0;
    else
        return 1;
}
