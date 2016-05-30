#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <stdio.h>
#include <stdlib.h>

typedef struct kruskal_edge_quick_sort_s {
	int index_vex_1;
	int index_vex_2;
	int weight;
} quick_sort_elemtype;

//sort an array
void quick_sort(struct kruskal_edge_s * array, int head, int tail);

//move one element to the correct location
//return the location of the array
int move(struct kruskal_edge_s * array, int head, int tail);

#endif
