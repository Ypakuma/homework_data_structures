#ifndef KMP_H
#define KMP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string\homework_string.h"

/********************************
* aim:       match string by KMP algorithm.
* parameter: string_aimed:   the aimed string(long).
*            string_matched: the matched string(short).
* return:    a number, which is the location where two strings match, in the aimed string.
********************************/
int KMP(char * string_aimed, char * string_matched);

/********************************
* aim:       create matched string(short)'s "next array".
* parameter: string_matched: the matched string(short).
* return:    the "next array".
********************************/
int * KMP_create_next_array(char * string_matched);

int KMP_get_next_value(char * string_matched, int * next_array, int num1, int num2);

/********************************
* aim:       match two string.
* parameter: string_aimed:   the aimed string(long).
*            string_matched: the matched string(short).
*            next          : the matched string(short)'s "next array". 
* return:    a number, which is the location where two strings match, in the aimed string.
********************************/
int KMP_match(char * string_aimed, char * string_matched, int * next);

#endif
