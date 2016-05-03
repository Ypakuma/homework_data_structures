#include "quick_sort.h"

void QuickSort(seq_binary_tree_node * array, int head, int tail)
{
	if (head >= tail)
		return;
	
	int middle;
	middle = MoveNode(array, head, tail);

	QuickSort(array, head, middle - 1);
	QuickSort(array, middle + 1, tail);
}

int MoveNode(seq_binary_tree_node * array, int head, int tail)
{
	seq_binary_tree_node node;
	node = array[head];
	int array_head = head;

	for (;;) {
		while (array[tail].weight >= node.weight && head < tail)
			tail--;
		if (head >= tail)
			break;
		FixParent(array, tail, head);
		array[head++] = array[tail];

		while (array[head].weight <= node.weight && head < tail)
			head++;
		if (head >= tail)
			break;
		FixParent(array, head, tail);
		array[tail--] = array[head];
	}
	FixParent(array, array_head, head);
	array[head] = node;

	return head;
}

void FixParent(seq_binary_tree_node * array, int num_node, int index)
{
	if (array[array[num_node].parent].lchild == num_node)
		array[array[num_node].parent].lchild = index;
	else
		array[array[num_node].parent].rchild = index;
}