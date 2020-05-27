/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_printf
*/

#include "my.h"

int next_flag(int i, char const *str, va_list list)
{
    switch (str[i]) {
    case 'x' : my_putstr(convert_hexa(va_arg(list, int), 1));
        break;
    case 'X' : my_putstr(convert_hexa(va_arg(list, int), 2));
        break;
    case 'u' : my_put_nbr(va_arg(list, int));
        break;
    case 'p' : my_putstr(convert_hexa(va_arg(list, int), 3));
        break;
    }
}

int gest_flags(int i, char const *str, va_list list)
{
    switch (str[i]) {
    case 'd' : my_put_nbr(va_arg(list, int));
        break;
    case 'i' : my_put_nbr(va_arg(list, int));
        break;
    case 's' : my_putstr(va_arg(list, char *));
        break;
    case 'c' : my_putchar((char) va_arg(list, int));
        break;
    case '%' : my_putchar('%');
        break;
    case 'o' : my_put_nbr(convert_octal(va_arg(list, int)));
        break;
    case 'S' : non_printable_char(i, str, list);
        break;
    case 'b' : binary_flag(i, str, list);
        break;
    }
    next_flag(i, str, list);
    return (i);
}

void binary_flag(int i, char const *str, va_list list)
{
    int nb = va_arg(list, int);
    char *binary = malloc((nb + 2) * sizeof(char));

    if (nb < 0)
        my_putchar('-');
    for (int j = 0; nb != 0; j++) {
        if (nb % 2 == 1)
            binary[j] = '1';
        else
            binary[j] = '0';
        nb = nb / 2;
    }
    my_putstr(my_revstr(binary));
    free(binary);
}

int non_printable_char(int i, char const *str, va_list list)
{
    char *arg = va_arg(list, char *);
    int nbr;

    for (int j = 0; arg[j] != '\0'; j++) {
        if (arg[j] >= ' ' && arg[j] < 127)
            my_putchar(arg[j]);
        if (arg[j] < ' ' || arg[j] >= 127) {
            nbr = arg[j];
            my_putchar('\\');
            nbr = convert_octal(nbr);
            if (nbr < 100)
                my_putchar('0');
            if (nbr < 10)
                my_putchar('0');
            my_put_nbr(nbr);
        }
    }
    return (0);
}

int my_printf(char const *str, ...)
{
    va_list list;

    va_start(list, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (error_handling(i, str) == 1) {
            write(2, ERROR_MSG, my_strlen(ERROR_MSG));
            return (84);
        }
        if (str[i] == '%')
            i = gest_flags(i + 1, str, list) + 1;
        if (str[i - 1] == '%')
            i = gest_flags(i, str, list);
        if (str[i] == '\n')
            my_putchar('\n');
        if (str[i] == '\0')
            break;
        if (str[i] >= ' ' && str[i] < '%' || str[i] > '%' && str[i] <= 127)
            my_putchar(str[i]);
    }
    va_end(list);
    return (0);
}
