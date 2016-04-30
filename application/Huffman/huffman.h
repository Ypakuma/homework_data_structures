#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "seq_binary_tree\seq_binary_tree.h"
#include "quick_tree\quick_sort.h"

/********************************
* aim:       create a huffman tree according to a tree.
* parameter: normal_tree: the normal tree.
* return:    the address of huffman tree.
********************************/
seq_binary_tree create_huffman_tree(seq_binary_tree normal_tree);

#endif