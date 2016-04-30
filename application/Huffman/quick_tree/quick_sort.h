#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <stdio.h>
#include <stdlib.h>
#include "../seq_binary_tree/seq_binary_tree.h"

typedef int quick_sort_elemtype;

//sort tree by its nodes' weight
void quick_sort(seq_binary_tree_node * array, int head, int tail);

//move one element to the correct location
//return the location of the array
int move(seq_binary_tree_node * array, int head, int tail);

//after move, the node's parent may not correct
//this function can fix it, and function must locate before move a node 
void fix_parent(seq_binary_tree_node * array, int num_node, int index);

#endif
