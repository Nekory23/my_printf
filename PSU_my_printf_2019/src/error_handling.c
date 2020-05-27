/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** error handling
*/

#include "my.h"

int error_handling(int i, char const *str)
{
    char *flags = "disc%oSbxXp";

    while (str[i] != '%')
        i = i + 1;
        if (str[i] == '\0')
            return (0);
    for (int j = 0; flags[j] != '\0'; j++) {
        if (str[i + 1] == flags[j])
            return (0);
        if (flags[j + 1] == '\0')
            return (1);
    }
}
