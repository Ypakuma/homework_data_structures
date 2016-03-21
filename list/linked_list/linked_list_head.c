#include "linked_list_head.h"

void LinkedListHeadInit(linked_list * plist)
{
	*plist = (linked_list) malloc(sizeof(linked_node));
	if (!(*plist)) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}
	(*plist)->next = NULL;
}

int LinkedListHeadLength(linked_list list)
{
	linked_node * pnode = list;
	int num = 0;

	while (pnode->next) {
		num++;
		pnode = pnode->next;
	}
	
	return num;
}

elem_type LinkedListHeadGet(linked_list list, int index)
{
	if (LinkedListHeadEmpty(list)) {
		printf("Empty list.\n");
		exit(0);
	}

	linked_node * pnode = list->next;
	int num = 1;

	while (num < index && pnode->next) {
		pnode = pnode->next;
		num++;
	}
	if (num == index)
		return pnode->elem;
	printf("Input too much.\n");
	exit(0);
}

linked_node * LinkedListHeadLocate(linked_list list, elem_type elem)
{
	if (LinkedListHeadEmpty(list)) {
		printf("Empty list.\n");
		exit(0);
	}

	linked_node * pnode = list->next;
	int index = 1;

	while (pnode->elem != elem && pnode->next) {
		pnode = pnode->next;
		index++;
	}
	if (pnode->elem == elem)
		return pnode;
	printf("Not find.\n");
	return NULL;
}

int LinkedListHeadIndex(linked_list list, linked_node * locat)
{
	if (LinkedListHeadEmpty(list)) {
		printf("Empty list.\n");
		exit(0);
	}

	linked_node * pnode = list->next;
	int num = 1;
	while (pnode != locat && pnode->next) {
		pnode = pnode->next;
		num++;
	}
	if (pnode == locat)
		return num;
	printf("Illegal location.\n");
	exit(0);
}

linked_node * LinkedListHeadFormer(linked_list list, elem_type elem)
{
	linked_node * former = list;
	linked_node * pnode = former->next;

	/*if (pnode->elem == elem) {
		printf("No former.\n");
		exit(0);
	}*/
	while (pnode->elem != elem && pnode->next) {
		former = pnode;
		pnode = pnode->next;
	}
	if (pnode->elem == elem)
		return former;
	printf("Illegal input.\n");
	exit(0);
}

linked_node * LinkedListHeadLatter(linked_list list, elem_type elem)
{
	if (LinkedListHeadEmpty(list)) {
		printf("Empty list.\n");
		exit(0);
	}
	
	linked_node * pnode = list->next;

	while (pnode->elem != elem && pnode->next) {
		pnode = pnode->next;
	}
	if (pnode->elem == elem)
		return pnode->next;
	printf("Illegal input.\n");
	exit(0);
}

void LinkedListHeadInsert(linked_list list, linked_node * locat, elem_type elem)
{
	linked_node * pnode = (linked_node *) malloc(sizeof(linked_node));
	pnode->elem = elem;
	pnode->next = locat;

	if (!locat) {
		linked_node * last = list;
		int num = 0;

		while (last->next) {
			num++;
			last = last->next;
		}
		last->next = pnode;
		return;
	}

	linked_node * former = LinkedListHeadFormer(list, locat->elem);
	former->next = pnode;
}

void LinkedListHeadDelete(linked_list list, linked_node * locat)
{
	linked_node * former;
	if (list->next == locat)
		former = list;
	else
		former = LinkedListHeadFormer(list, locat->elem);

	former->next = locat->next;
	
	free(locat);
}

bool LinkedListHeadEmpty(linked_list list)
{
	if (list->next)
		return false;
	else
		return true;
}

void LinkedListHeadClear(linked_list list)
{
	if (LinkedListHeadEmpty(list))
		return;

	linked_node * pnode = list->next;
	linked_node * latter;

	while (pnode->next) {
		latter = pnode->next;
		free(pnode);
		pnode = latter;
	}
	free(pnode);

	list->next = NULL;
}

void LinkedListHeadDestroy(linked_list list)
{
	LinkedListHeadClear(list);
	free(list);
}

void LinkedListHeadAdd(linked_list list, elem_type elem)
{
	if (LinkedListHeadEmpty(list)) {
		linked_node * pnode = (linked_node *) malloc(sizeof(linked_node));
		pnode->elem = elem;
		pnode->next = NULL;
		list->next = pnode;
		return;
	}

	linked_node * pnode = list->next;

	while (elem >= pnode->elem && pnode->next) {
		if (elem <= pnode->next->elem) {
			LinkedListHeadInsert(list, pnode->next, elem);
			return;
		}
		pnode = pnode->next;
	}
	if (elem < pnode->elem) {
		LinkedListHeadInsert(list, pnode, elem);
		return;
	}
	LinkedListHeadInsert(list, pnode->next, elem);
}

void LinkedListHeadCat(linked_list list1, linked_list list2)
{
	linked_node * pnode = list1;

	while (pnode->next)
		pnode = pnode->next;
	pnode->next = list2->next;
}

void LinkedListHeadUnion(linked_list list1, linked_list list2, linked_list list3)
{
	linked_node * pnode1;
	linked_node * pnode2;

	pnode1 = list1->next;
	pnode2 = list2->next;

	LinkedListHeadClear(list3);

	while (pnode1 && pnode2) {
		if (pnode1->elem <= pnode2->elem) {
			LinkedListHeadAdd(list3, pnode1->elem);
			pnode1 = pnode1->next;
		}
		else {
			LinkedListHeadAdd(list3, pnode2->elem);
			pnode2 = pnode2->next;
		}
	}
	while (pnode1) {
		LinkedListHeadAdd(list3, pnode1->elem);
		pnode1 = pnode1->next;
	}
	while (pnode2) {
		LinkedListHeadAdd(list3, pnode2->elem);
		pnode2 = pnode2->next;
	}
}
