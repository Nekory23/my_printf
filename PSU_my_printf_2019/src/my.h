/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my.h
*/

#ifndef __MY_H__
#define __MY_H__

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

void my_putchar(char c);
int my_putstr(char const *str);
int my_put_str(int nb);
int my_strlen(char const *str);
int my_put_nbr(int nb);
char *my_revstr(char *str);
char *my_strcpy(char *dest, char const *src);
int error_handling(int i, char const *str);
int convert_octal(int nbr);
char *convert_hexa_min(int nbr, char *hexa);
char *convert_hexa_maj(int nbr, char *hexa);
char *convert_hexa(int nbr, int mode);
int my_printf(const char *format, ...);
int non_printable_char(int i, char const *str, va_list list);
void binary_flag(int i, char const *str, va_list list);

#define ERROR_MSG "error, flag not handled\n"

#endif
