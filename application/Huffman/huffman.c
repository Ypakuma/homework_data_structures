#include "huffman.h"

seq_binary_tree create_huffman_tree(seq_binary_tree normal_tree)
{
	seq_binary_tree huffman_tree;

	huffman_tree = SeqBinaryTreeInit(0, 0, normal_tree->num_node * 2 - 1);
	quick_sort(normal_tree->node, 0, normal_tree->num_node - 1);

	//copy normal tree to Huffman tree's fronter node
	for (int i = 0; i < normal_tree->num_node; i++) {
		huffman_tree->node[i].weight = normal_tree->node[i].weight;
		huffman_tree->node[i].elem = normal_tree->node[i].elem;
		huffman_tree->node[i].lchild = -1;
		huffman_tree->node[i].rchild = -1;
		huffman_tree->num_node = i + 1;
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
	for (int i = huffman_tree->num_node; i < huffman_tree->len; i++) {
		huffman_tree->node[i].lchild = min_index[0];
		huffman_tree->node[i].rchild = min_index[1];
		huffman_tree->node[i].weight = huffman_tree->node[min_index[0]].weight + huffman_tree->node[min_index[1]].weight;
		huffman_tree->node[min_index[0]].parent = i;
		huffman_tree->node[min_index[1]].parent = i;
		huffman_tree->num_node++;

		//2 * normal_tree->num_node - i = normal_tree->num_node - (i - normal_tree->num_node)
		//it is the index of the last elements in min_index array
		int j = 2;
		while(j < 2 * normal_tree->num_node - i) {
			if (huffman_tree->node[i].weight <= huffman_tree->node[min_index[j]].weight)
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
	huffman_tree->node[huffman_tree->len - 1].parent = -1;

	return huffman_tree;
}

