#include "linked_list_cir_doub.h"

cir_doub_list LinkedListCirDoubInit(void)
{
	cir_doub_node * pnode = (cir_doub_node*) malloc(sizeof(cir_doub_node));
	if (!pnode) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}

	cir_doub_list plist = pnode;
	plist->prior = pnode;
	pnode->next = pnode;

	return plist;
}

bool LinkedListCirDoubEmpty(cir_doub_list list)
{
	return list->next == list;
}

void LinkedListCirDoubInsert(cir_doub_node * locat, linked_list_cir_doub_elemtype elem)
{
	cir_doub_node * pnode = (cir_doub_node *) malloc(sizeof(cir_doub_node));
	if (!pnode) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}

	pnode->elem = elem;
	pnode->prior = locat;
	pnode->next = locat->next;
	locat->next = pnode;
	pnode->next->prior = pnode;
}

void LinkedListCirDoubAdd(cir_doub_list list, linked_list_cir_doub_elemtype elem)
{
	if (LinkedListCirDoubEmpty(list)) {
		LinkedListCirDoubInsert(list, elem);
		return;
	}

	cir_doub_node * pnode = list->next;
	cir_doub_node * former = list;

	while (pnode != list && elem > pnode->elem) {
		former = pnode;
		pnode = pnode->next;
	}
	LinkedListCirDoubInsert(former, elem);
}

void LinkedListCirDoubClear(cir_doub_list list)
{
	cir_doub_node * pnode = list->next;
	cir_doub_node * latter = pnode->next;

	while (latter !=list) {
		free(pnode);
		pnode = latter;
		latter = pnode->next;
	}
	free(pnode);
	list->next = list;
	list->prior = list;
}

void LinkedListCirDoubDestroy(cir_doub_list list)
{
	if (list) {
		if (!LinkedListCirDoubEmpty(list))
			LinkedListCirDoubClear(list);
		free(list);
		list = NULL;
	}
}

void LinkedListCirDoubDelete(cir_doub_list list, cir_doub_node * locat)
{
	if (LinkedListCirDoubEmpty(list)) {
		printf("Empty list.\n");
		return;
	}
	if (locat == list->next) {
		printf("Can't delete the head node.\n");
		return;
	}

	locat->prior->next = locat->next;
	locat->next->prior = locat->prior;
	free(locat);
}

cir_doub_node * LinkedListCirDoubGet(cir_doub_list list, int index)
{
	if (LinkedListCirDoubEmpty(list)) {
		printf("Empty list.\n");
		return NULL;
	}

	cir_doub_node * pnode = list->next;
	int num = 1;

	while (num < index && pnode != list) {
		pnode = pnode->next;
		num++;
	}
	if (num == index)
		return pnode;
	printf("Input too much.\n");
	return NULL;
}

cir_doub_node * LinkedListCirDoubLocate(cir_doub_list list, linked_list_cir_doub_elemtype elem)
{
	if (LinkedListCirDoubEmpty(list)) {
		printf("Empty list.\n");
		return NULL;
	}

	cir_doub_node * pnode = list->next;

	while (pnode->elem != elem && pnode != list)
		pnode = pnode->next;

	if (pnode->elem == elem)
		return pnode;
	printf("Not find.\n");
	return NULL;
}

int LinkedListCirDoubLength(cir_doub_list list)
{
	if (LinkedListCirDoubEmpty(list)) {
		return 0;
	}

	cir_doub_node * pnode = list->next;
	int num = 0;

	while (pnode != list) {
		num++;
		pnode = pnode->next;
	}

	return num;
}

void LinkedListCirDoubCat(cir_doub_list list1, cir_doub_list * list2)
{
	list1->prior->next = (*list2)->next;
	(*list2)->next->prior = list1->prior;
	list1->prior = (*list2)->prior;
	list1->prior->next = list1;

	free(*list2);
	(*list2) = NULL;
}

void LinkedListCirDoubUnion(cir_doub_list list1, cir_doub_list * list2)
{
	cir_doub_node * former1 = list1;
	cir_doub_node * pnode1 = former1->next;
	cir_doub_node * pnode2 = (*list2)->next;


	while (pnode1 != list1 && pnode2 != (*list2)) {
		if (pnode1->elem > pnode2->elem) {
			cir_doub_node * ptemp = pnode2->next;
			pnode2->next = pnode1;
			pnode2->prior = former1;
			former1->next = pnode2;
			pnode2->next->prior = pnode2;
			pnode2 = ptemp;
			former1 = former1->next;
		}
		else {
			pnode1 = pnode1->next;
			former1 = former1->next;
		}
	}

	if (pnode2 != (*list2)) {
		former1->next = pnode2;
		pnode2->prior = former1;
		list1->prior = (*list2)->prior;
		(*list2)->prior->next = list1;
	}
	free(*list2);
	(*list2) = NULL;
}

void SeqToLinkedCirDoub(seq_list s_list, cir_doub_list l_list)
{
	int num = s_list->num_elem;
	while (num) {
		LinkedListCirDoubAdd(l_list, s_list->elem[num - 1]);
		num--;
	}
}
