#include "quick_sort.h"

void quick_sort(seq_binary_tree_node * array, int head, int tail)
{
	if (head >= tail)
		return;
	
	int middle;
	middle = move(array, head, tail);

	quick_sort(array, head, middle - 1);
	quick_sort(array, middle + 1, tail);
}

int move(seq_binary_tree_node * array, int head, int tail)
{
	seq_binary_tree_node node;
	node = array[head];
	int array_head = head;

	for (;;) {
		while (array[tail].weight >= node.weight && head < tail)
			tail--;
		if (head >= tail)
			break;
		fix_parent(array, tail, head);
		array[head++] = array[tail];

		while (array[head].weight <= node.weight && head < tail)
			head++;
		if (head >= tail)
			break;
		fix_parent(array, head, tail);
		array[tail--] = array[head];
	}
	fix_parent(array, array_head, head);
	array[head] = node;

	return head;
}

void fix_parent(seq_binary_tree_node * array, int num_node, int index)
{
	if (array[array[num_node].parent].lchild == num_node)
		array[array[num_node].parent].lchild = index;
	else
		array[array[num_node].parent].rchild = index;
}