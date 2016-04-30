#include "quick_sort.h"

void quick_sort(int * array, int head, int tail)
{
	if (head >= tail)
		return;
	
	int middle;
	middle = move(array, head, tail);
	quick_sort(array, head, middle - 1);
	quick_sort(array, middle + 1, tail);	
}

int move(int * array, int head, int tail)
{
	quick_sort_elemtype elem = array[head];

	for (;;) {
		while (array[tail] >= elem && head < tail)
			tail--;
		if (head >= tail)
			break;
		array[head++] = array[tail];

		while (array[head] <= elem && head < tail)
			head++;
		if (head >= tail)
			break;
		array[tail--] = array[head];
	}
	array[head] = elem;

	return head;
}