#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "seq_binary_tree\seq_binary_tree.h"
#include "quick_sort\quick_sort.h"
#include "seq_stack\seq_stack.h"

typedef seq_binary_tree huffman_tree;
typedef struct huffman_code_node_s {
	char character;
	char * code;
}huffman_code_node;
typedef huffman_code_node * huffman_code_list;

/********************************
* aim:       create a huffman tree according to a tree.
* parameter: normal_tree: the normal tree.
* return:    the address of huffman tree.
********************************/
huffman_tree CreateHuffmanTree(seq_binary_tree normal_tree);

/********************************
* aim:       create a huffman code list according to huffman tree.
* parameter: tree: the huffman tree.
* return:    the address of huffman code list.
********************************/
huffman_code_list CreateHuffmanCodeList(huffman_tree tree);

/********************************
* aim:       decode the huffman code.
* parameter: code_string:  the huffman code string which will be decoded.
*            huffman_tree: the huffman tree.
* return:    the address of huffman code list.
********************************/
void CodeToCharHuffmanCode(char * code_string, huffman_tree huffman_tree);

#endif