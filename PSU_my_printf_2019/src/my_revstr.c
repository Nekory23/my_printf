/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** task03 my_revstr
*/

void my_putchar(char c);

char *my_revstr(char *str)
{
    int nbr = 0;
    char temp;
    char *begin;
    char *end;

    begin = str;
    end = str;
    while (str[nbr] != '\0') {
        end = end + 1;
        nbr = nbr + 1;
    }
    end = end - 1;
    for (int j = 0; j < nbr/2; j++) {
        temp = *end;
        *end = *begin;
        *begin = temp;
        end = end - 1;
        begin = begin + 1;
    }
    str[nbr + 1] = '\0';
    return (str);
}
