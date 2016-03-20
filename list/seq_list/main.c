#include <stdio.h>
#include "seq_list.h"


int main(void)
{
	seq_list * list1 = SeqListInit();
	seq_list * list2 = SeqListInit();
	seq_list * list3 = SeqListInit();

	SeqListAdd(list1, 1);
	SeqListAdd(list1, 3);
	SeqListAdd(list1, 5);
	SeqListAdd(list2, 2);
	SeqListAdd(list2, 4);
	SeqListAdd(list2, 6);

	list3 = SeqListUnion(list1, list2);
	SeqListCat(list1, list2);

	return 0;
}
