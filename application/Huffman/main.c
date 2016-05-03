#include "huffman.h"

int main(void)
{
	seq_binary_tree tree;
	huffman_tree huffmanTree;
	huffman_code_list huffmanList;

	tree = SeqBinaryTreeInit('a', 1, 6);
	SeqBinaryTreeAddChildL(tree, 0, 'b', 3);
	SeqBinaryTreeAddChildR(tree, 0, 'c', 2);
	SeqBinaryTreeAddChildL(tree, 1, 'd', 5);
	SeqBinaryTreeAddChildR(tree, 1, 'e', 4);
	SeqBinaryTreeAddChildR(tree, 2, 'f', 6);

	huffmanTree = CreateHuffmanTree(tree);
	huffmanList = CreateHuffmanCodeList(huffmanTree);
	
	for (int i = 0; i < 6; i++) {
		printf("%c  ", huffmanList[i].character);
		printf("%s", huffmanList[i].code);
		printf("\n");
	}
	
	CodeToCharHuffmanCode("10000001111011001", huffmanTree);

	return 0;
}