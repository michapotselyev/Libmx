#pragma once

#ifndef CALC_H
#define CALC_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>

//Utils pack
void mx_printchar(char);
void mx_print_unicode(wchar_t);
void mx_printstr(const char*);
void mx_print_strarr(char**, const char*);
void mx_printint(int);
double mx_pow(double, unsigned int);
int mx_sqrt(int);
char *mx_nbr_to_hex(unsigned long);
unsigned long mx_hex_to_nbr(const char*);
char *mx_itoa(int);
void mx_foreach(int*, int, void(*f)(int));
int mx_binary_search(char**, int, const char*, int*);
int mx_bubble_sort(char**, int);
int mx_quicksort(char**, int, int);

//String pack
int mx_strlen(const char*);
void mx_swap_char(char*, char*);
void mx_str_reverse(char*);
void mx_strdel(char**);
void mx_del_strarr(char***);
int mx_get_char_index(const char*, char);
char *mx_strdup(const char*);

#endif

//#include "../inc/libmx.h"