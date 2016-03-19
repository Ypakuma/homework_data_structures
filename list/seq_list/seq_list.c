#include "seq_list.h"

seq_list* SeqListInit (void)
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

elem_type SeqListGet(seq_list * list, int sub)
{
	if (sub >= 0 && sub < list->num_elem) {
		return list->elem[sub];
	}
	printf("Illegal input.\n");
	exit(0);
}

int SeqListLocate(seq_list * list, elem_type elem)
{
	for (int index = 0; index < list->num_elem; index++)
		if (list->elem[index] == elem)
			return index;
	printf("Illegal input.\n");
	exit(0);
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

void SeqListInsert(seq_list * list, int index, elem_type elem)
{
	if (list->num_elem == MAX_ELEM) {
		printf("The list is full.\n");
		exit(0);
	}

	if (index < 0 || index > list->num_elem) {
		printf("Illegal input.\n");
		exit(0);
	}

	int last = list->num_elem;
	while (last > index) {
		list->elem[last] = list->elem[last - 1];
		last--;
	}

	list->elem[index] = elem;
	list->num_elem++;
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
