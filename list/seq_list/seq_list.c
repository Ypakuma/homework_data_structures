#include "seq_list.h"

seq_list SeqListInit (int num_elem)
{
	struct seq_list_s * plist = (struct seq_list_s*) malloc(sizeof(struct seq_list_s));
	if (!plist) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}
	plist->elem = (seq_list_elemtype *) malloc(sizeof(seq_list_elemtype) * num_elem);
	if (!(plist->elem)) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}

	plist->num_elem = num_elem;
	plist->len = 0;

	return plist;
}

int SeqListLength(seq_list list)
{
	return list->len;
}

seq_list_elemtype SeqListGet(seq_list list, int index)
{
	if (index >= 0 && index < list->len) {
		return list->elem[index];
	}
	printf("Illegal input.\n");
	exit(0);
}

int SeqListLocate(seq_list list, seq_list_elemtype elem)
{
	for (int index = 0; index < list->len; index++)
		if (list->elem[index] == elem)
			return index;
	printf("Not find.\n");
	return -1;
}

seq_list_elemtype SeqListFormer(seq_list list, seq_list_elemtype elem)
{
	int loc = SeqListLocate(list, elem);
	return SeqListGet(list, loc - 1);
}

seq_list_elemtype SeqListLatter(seq_list list, seq_list_elemtype elem)
{
	int loc = SeqListLocate(list, elem);
	return SeqListGet(list, loc + 1);
}

bool SeqListInsert(seq_list list, int index, seq_list_elemtype elem)
{
	if (list->len == list->num_elem) {
		printf("The list is full.\n");
		return false;
	}

	if (index < 0 || index > list->len) {
		printf("Illegal input.\n");
		return false;
	}

	int last = list->len;
	while (last > index) {
		list->elem[last] = list->elem[last - 1];
		last--;
	}

	list->elem[index] = elem;
	list->len++;
	return true;
}

void SeqListRemove(seq_list list, int index)
{
	if (SeqListEmpty(list)) {
		printf("The list is empty.\n");
		exit(0);
	}

	while (index < list->len) {
		list->elem[index] = list->elem[index + 1];
		index++;
	}

	list->len--;
}

bool SeqListEmpty(seq_list list)
{
	if (list->len == 0)
		return true;
	else
		return false;
}

void SeqListClear(seq_list list)
{
	list->len = 0;
}

void SeqListDestroy(seq_list list)
{
	free(list);
	list = NULL;
}

void SeqListAdd(seq_list list, seq_list_elemtype elem)
{
	list->elem[list->len] = elem;
	list->len++;
}

void SeqListDelete(seq_list list)
{
	list->len--;
}

void SeqListCat(seq_list list1, seq_list list2)
{
	if ((list1->len + list2->len) > list1->num_elem) {
		printf("Too many elements.\n");
		exit(0);
	}
	
	for (int index2 = 0; index2 < list2->len; index2++) {
		list1->elem[list1->len] = list2->elem[index2];
		list1->len++;
	}
}

seq_list SeqListUnion(seq_list list1, seq_list list2)
{
	int new_list_len = list1->len + list2->len;

	seq_list new_list = SeqListInit(new_list_len);
	int index1 = 0, index2 = 0;

	while (index1 < list1->len && index2 < list2->len) {
		if (list1->elem[index1] <= list2->elem[index2]) {
			SeqListAdd(new_list, list1->elem[index1]);
			index1++;
			new_list->len++;
		}
		else {
			SeqListAdd(new_list, list2->elem[index2]);
			index2++;
			new_list->len++;
		}
	}

	if (index1 < list1->len) {
		while (index1 < list1->len) {
			SeqListAdd(new_list, list1->elem[index1]);
			index1++;
			new_list->len++;
		}
	}
	else {
		while (index2 < list2->len) {
			SeqListAdd(new_list, list2->elem[index2]);
			index2++;
			new_list->len++;
		}
	}
	return new_list;
}
