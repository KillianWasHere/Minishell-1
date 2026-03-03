/*
** EPITECH PROJECT, 2025
** my_evil_str
** File description:
** C_pool04 | task04
*/
#include "../../includes/my.h"

static void my_swap(char *string, int pos1, int pos2)
{
    int c;

    c = string[pos1];
    string[pos1] = string[pos2];
    string[pos2] = c;
}

char *my_revstr(char *str)
{
    int len = my_strlen(str);

    for (int pos = 0; pos < len / 2; pos++) {
        my_swap(str, pos, (len - 1) - pos);
    }
    return (str);
}
