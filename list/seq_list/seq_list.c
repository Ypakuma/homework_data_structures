#include "seq_list.h"

seq_list * SeqListInit (void)
{
	seq_list * plist = (seq_list*) malloc(sizeof(seq_list));
	if (!plist) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}
	plist->num_elem = 0;

	return plist;
}

int SeqListLength(seq_list * list)
{
	return list->num_elem;
}

elem_type SeqListGet(seq_list * list, int index)
{
	if (index >= 0 && index < list->num_elem) {
		return list->elem[index];
	}
	printf("Illegal input.\n");
	exit(0);
}

int SeqListLocate(seq_list * list, elem_type elem)
{
	for (int index = 0; index < list->num_elem; index++)
		if (list->elem[index] == elem)
			return index;
	printf("Not find.\n");
	return -1;
}

elem_type SeqListFormer(seq_list * list, elem_type elem)
{
	int loc = SeqListLocate(list, elem);
	return SeqListGet(list, loc - 1);
}

elem_type SeqListLatter(seq_list * list, elem_type elem)
{
	int loc = SeqListLocate(list, elem);
	return SeqListGet(list, loc + 1);
}

bool SeqListInsert(seq_list * list, int index, elem_type elem)
{
	if (list->num_elem == MAX_ELEM) {
		printf("The list is full.\n");
		return false;
	}

	if (index < 0 || index > list->num_elem) {
		printf("Illegal input.\n");
		return false;
	}

	int last = list->num_elem;
	while (last > index) {
		list->elem[last] = list->elem[last - 1];
		last--;
	}

	list->elem[index] = elem;
	list->num_elem++;
	return true;
}

void SeqListRemove(seq_list * list, int index)
{
	if (SeqListEmpty(list)) {
		printf("The list is empty.\n");
		exit(0);
	}

	while (index < list->num_elem) {
		list->elem[index] = list->elem[index + 1];
		index++;
	}

	list->num_elem--;
}

bool SeqListEmpty(seq_list * list)
{
	if (list->num_elem == 0)
		return true;
	else
		return false;
}

void SeqListClear(seq_list * list)
{
	list->num_elem = 0;
}

void SeqListDestroy(seq_list * list)
{
	free(list);
	list = NULL;
}

void SeqListAdd(seq_list * list, elem_type elem)
{
	list->elem[list->num_elem] = elem;
	list->num_elem++;
}

void SeqListDelete(seq_list * list)
{
	list->num_elem--;
}

void SeqListCat(seq_list * list1, seq_list * list2)
{
	if ((list1->num_elem + list2->num_elem) > MAX_ELEM) {
		printf("Too many elements.\n");
		exit(0);
	}
	
	for (int index2 = 0; index2 < list2->num_elem; index2++) {
		list1->elem[list1->num_elem] = list2->elem[index2];
		list1->num_elem++;
	}
}

seq_list * SeqListUnion(seq_list * list1, seq_list * list2)
{
	if ((list1->num_elem + list2->num_elem) > MAX_ELEM) {
		printf("Too many elements.\n");
		exit(0);
	}

	seq_list * new_list = SeqListInit();
	int index1 = 0, index2 = 0;

	while (index1 < list1->num_elem && index2 < list2->num_elem) {
		if (list1->elem[index1] <= list2->elem[index2]) {
			SeqListAdd(new_list, list1->elem[index1]);
			index1++;
			new_list->num_elem++;
		}
		else {
			SeqListAdd(new_list, list2->elem[index2]);
			index2++;
			new_list->num_elem++;
		}
	}

	if (index1 < list1->num_elem) {
		while (index1 < list1->num_elem) {
			SeqListAdd(new_list, list1->elem[index1]);
			index1++;
			new_list->num_elem++;
		}
	}
	else {
		while (index2 < list2->num_elem) {
			SeqListAdd(new_list, list2->elem[index2]);
			index2++;
			new_list->num_elem++;
		}
	}
	return new_list;
}
