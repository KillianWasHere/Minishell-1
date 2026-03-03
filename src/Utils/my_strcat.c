/*
** EPITECH PROJECT, 2025
** my_sudo
** File description:
** Substitute user do
*/
#include "../../includes/my.h"

char *my_strcat(char *dest, char *src)
{
    int len_src = my_strlen(src);
    int pos = 0;

    for (int i = 0; dest[i] != '\0'; i++)
        pos++;
    for (int i = 0; i < len_src; i++) {
        dest[pos] = src[i];
        pos++;
    }
    dest[pos] = '\0';
    return dest;
}
