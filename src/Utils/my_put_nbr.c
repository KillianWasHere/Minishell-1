/*
** EPITECH PROJECT, 2025
** organized
** File description:
** let's organize the warehouse
*/
#include <unistd.h>
#include "../../includes/my.h"

void my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(-nb);
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    } else {
        my_putchar(nb + '0');
    }
}
