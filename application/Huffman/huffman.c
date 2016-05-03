#include "huffman.h"

huffman_tree CreateHuffmanTree(seq_binary_tree normal_tree)
{
	huffman_tree huffman;

	huffman = SeqBinaryTreeInit(0, 0, normal_tree->num_node * 2 - 1);
	QuickSort(normal_tree->node, 0, normal_tree->num_node - 1);

	//copy normal tree to Huffman tree's fronter node
	for (int i = 0; i < normal_tree->num_node; i++) {
		huffman->node[i].weight = normal_tree->node[i].weight;
		huffman->node[i].elem = normal_tree->node[i].elem;
		huffman->node[i].lchild = -1;
		huffman->node[i].rchild = -1;
		huffman->num_node = i + 1;
	}

	//this array to storage the index of Huffman tree's nodes from min to max by its weight
	int * min_index = (int*) malloc(sizeof(int) * normal_tree->num_node);
	if (!min_index) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}
	for (int i = 0; i < normal_tree->num_node; i++) {
		min_index[i] = i;
	}

	//storage other nodes in Huffman tree
	for (int i = huffman->num_node; i < huffman->len; i++) {
		huffman->node[i].lchild = min_index[0];
		huffman->node[i].rchild = min_index[1];
		huffman->node[i].weight = huffman->node[min_index[0]].weight + huffman->node[min_index[1]].weight;
		huffman->node[min_index[0]].parent = i;
		huffman->node[min_index[1]].parent = i;
		huffman->num_node++;

		//2 * normal_tree->num_node - i = normal_tree->num_node - (i - normal_tree->num_node)
		//it is the index of the last elements in min_index array
		int j = 2;
		while(j < 2 * normal_tree->num_node - i) {
			if (huffman->node[i].weight <= huffman->node[min_index[j]].weight)
				break;
			else
				min_index[j - 2] = min_index[j];
			j++;
		}
		min_index[j - 2] = i;
		while (j < 2 * normal_tree->num_node - i) {
			min_index[j - 1] = min_index[j];
			j++;
		}
	}
	huffman->node[huffman->len - 1].parent = -1;

	return huffman;
}

huffman_code_list CreateHuffmanCodeList(huffman_tree tree)
{
	int num_list_node;
	num_list_node = (tree->num_node + 1) / 2;

	huffman_code_list list;
	list = (huffman_code_node*) malloc(sizeof(huffman_code_node) * num_list_node);
	if (!list) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}

	seq_stack code_stack;
	code_stack = SeqStackInit(num_list_node - 1);

	for (int i = 0; i < num_list_node; i++) {
		int num_node = i;
		int parent = tree->node[num_node].parent;
		int len_code = 0;

		while (parent > 0) {
			//left:0  right:1
			if (tree->node[parent].lchild == num_node)
				SeqStackPush(code_stack, '0');
			else
				SeqStackPush(code_stack, '1');
			len_code++;
			num_node = parent;
			parent = tree->node[num_node].parent;
		}

		list[i].character = tree->node[i].elem;
		list[i].code = (int*) malloc(sizeof(int) * (len_code + 1));
		if (!list[i].code) {
			printf("Fail to allocate memory.\n");
			exit(0);
		}

		for (int j = 0; j < len_code; j++)
			list[i].code[j] = SeqStackPop(code_stack);

		list[i].code[len_code] = 0;
	}

	return list;
}

void CodeToCharHuffmanCode(char * code_string, huffman_tree huffman_tree)
{
	int i = 0;
	int j = huffman_tree->len - 1;

	while (code_string[i] != 0) {
		while (!SeqBinaryTreeLeaf(huffman_tree, j)) {
			if (code_string[i] == '0')
				j = huffman_tree->node[j].lchild;
			else
				j = huffman_tree->node[j].rchild;
			i++;
		}
		printf("%c", huffman_tree->node[j].elem);
		j = huffman_tree->len - 1;
	}
}