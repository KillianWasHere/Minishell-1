/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** first part of the 42sh project
*/
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include "../includes/my.h"

int display_exit_error(int status)
{
    if (WIFSIGNALED(status)) {
        my_putstr(strsignal(WTERMSIG(status)));
        my_putchar('\n');
        return status;
    } else {
        return 0;
    }
}
