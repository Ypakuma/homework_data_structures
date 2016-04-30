#include "quick_sort.h"

int main(void)
{
	quick_sort_elemtype array[6] = { 1,3,2,5,4,6 };

	quick_sort(array, 0, 5);

	return 0;
}