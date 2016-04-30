#include "huffman.h"

int main(void)
{
	seq_binary_tree tree, huffman_tree;
	tree = SeqBinaryTreeInit(1, 1, 6);
	SeqBinaryTreeAddChildL(tree, 0, 3, 3);
	SeqBinaryTreeAddChildR(tree, 0, 2, 2);
	SeqBinaryTreeAddChildL(tree, 1, 5, 5);
	SeqBinaryTreeAddChildR(tree, 1, 4, 4);
	SeqBinaryTreeAddChildR(tree, 2, 6, 6);

	huffman_tree = create_huffman_tree(tree);

	return 0;
}