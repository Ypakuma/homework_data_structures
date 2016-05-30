#include "quick_sort.h"

void quick_sort(quick_sort_elemtype * array, int head, int tail)
{
	if (head >= tail)
		return;
	
	int middle;
	middle = move(array, head, tail);
	quick_sort(array, head, middle - 1);
	quick_sort(array, middle + 1, tail);	
}

int move(quick_sort_elemtype * array, int head, int tail)
{
	quick_sort_elemtype elem = array[head];

	for (;;) {
		while (array[tail].weight >= elem.weight && head < tail)
			tail--;
		if (head >= tail)
			break;
		array[head++] = array[tail];

		while (array[head].weight <= elem.weight && head < tail)
			head++;
		if (head >= tail)
			break;
		array[tail--] = array[head];
	}
	array[head] = elem;

	return head;
}