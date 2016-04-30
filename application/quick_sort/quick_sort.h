#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <stdio.h>
#include <stdlib.h>

typedef int quick_sort_elemtype;

//sort an array
void quick_sort(int * array, int head, int tail);

//move one element to the correct location
//return the location of the array
int move(int * array, int head, int tail);

#endif
