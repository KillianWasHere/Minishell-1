/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** Make your own shell.
*/

#include <stdlib.h>
#include "../../includes/my.h"
#include "../../includes/env_struct.h"

void display_env(char **my_env)
{
    int i = 0;

    while (my_env[i] != NULL) {
        my_putstr(my_env[i]);
        my_putchar('\n');
        i++;
    }
}
