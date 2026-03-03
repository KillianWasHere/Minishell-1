/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** Air Trafic control
*/

#include "../includes/my.h"
#include <stdlib.h>
#include <stdio.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (i = 0; i != n; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

char **add_word_to_list(char **w_array, int amount_of_word, char *str)
{
    int i = 0;
    int pos = 0;
    int l_word = 0;

    while ((str[i] != '\0' || str[i] != '\n') && pos < amount_of_word) {
        while (str[i] != ' ' && str[i] != '\n' && str[i] != '\0') {
            l_word++;
            i++;
        }
        if ((l_word != 0 && str[i] == ' ') || str[i] == '\n' ||
            str[i] == '\0') {
            w_array[pos] = malloc(sizeof(char) * l_word + 1);
            w_array[pos] = my_strncpy(w_array[pos], &str[i - l_word], l_word);
            l_word = 0;
            pos++;
        }
        i++;
        w_array[pos] = NULL;
    }
    return w_array;
}

int get_amount_of_word(char *buffer)
{
    int space = 0;
    int i = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == ' ')
            space++;
        i++;
    }
    return space + 1;
}

char **get_words(char *buffer)
{
    int amount_of_words = get_amount_of_word(buffer);
    char **word_arary = malloc(sizeof(char *) * (amount_of_words + 1));

    word_arary = add_word_to_list(word_arary, amount_of_words, buffer);
    return word_arary;
}
