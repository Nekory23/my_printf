/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** convert base
*/

#include "my.h"

int convert_octal(int nbr)
{
    int oct = 0;
    int times = 1;

    if (nbr < 0) {
        nbr = -nbr;
        my_putchar('-');
    }
    for (int i = 0; nbr != 0; i++) {
        oct = oct + ((nbr % 8) * times);
        times = times * 10;
        nbr = nbr / 8;
    }
    return (oct);
}

char *convert_hexa_min(int nbr, char *hexa)
{
    for (int i = 0; nbr != 0; i++) {
        hexa[i] = (nbr % 16) + '0';
        switch (hexa[i]) {
        case ':' : hexa[i] = 'a';
            break;
        case ';' : hexa[i] = 'b';
            break;
        case '<' : hexa[i] = 'c';
            break;
        case '=' : hexa[i] = 'd';
            break;
        case '>' : hexa[i] = 'e';
            break;
        case '?' : hexa[i] = 'f';
            break;
        }
        nbr = nbr / 16;
    }
    return (hexa);
}

char *convert_hexa_maj(int nbr, char *hexa)
{
    for (int i = 0; nbr != 0; i++) {
        hexa[i] = (nbr % 16) + '0';
        switch (hexa[i]) {
        case ':' : hexa[i] = 'A';
            break;
        case ';' : hexa[i] = 'B';
            break;
        case '<' : hexa[i] = 'C';
            break;
        case '=' : hexa[i] = 'D';
            break;
        case '>' : hexa[i] = 'E';
            break;
        case '?' : hexa[i] = 'F';
            break;
        }
        nbr = nbr / 16;
    }
    return (hexa);
}

char *convert_hexa(int nbr, int mode)
{
    char *hexa;
    char *dis = "0x";

    if (nbr < 0) {
        nbr = -nbr;
        my_putchar('-');
    }
    hexa = malloc((nbr + 2) * sizeof(char));
    if (mode == 1)
        convert_hexa_min(nbr, hexa);
    if (mode == 2)
        convert_hexa_maj(nbr, hexa);
    if (mode == 3) {
        my_putstr(dis);
        convert_hexa_min(nbr, hexa);
    }
    return (my_revstr(hexa));
    free(hexa);
}
