/*
** EPITECH PROJECT, 2025
** my_strcmp.c*
** File description:
** C_pool06 | task06
*/

#include "../../includes/my.h"

int my_strcmp(char *s1, char *s2)
{
    int len_s1 = my_strlen(s1);
    int len_s2 = my_strlen(s2);
    int i = 0;

    for (i = 0; i < len_s1 || i < len_s2; i++) {
        if (s1[i] > s2[i]) {
            return s1[i] - s2[i];
        }
        if (s2[i] > s1[i]) {
            return s2[i] - s1[i];
        }
    }
    return 0;
}
