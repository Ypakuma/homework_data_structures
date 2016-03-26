#include "linked_list_nohead.h"

linked_list * LinkedListNoHeadInit(void)
{
	return NULL;
}

int LinkedListNoHeadLength(linked_list * list)
{
	if (LinkedListNoHeadEmpty(list))
		return 0;

	linked_node * pnode = list;
	int num = 1;

	while (pnode->next) {
		num++;
		pnode = pnode->next;
	}

	return num;
}

elem_type LinkedListNoHeadGet(linked_list * list, int index)
{
	if (LinkedListNoHeadEmpty(list)) {
		printf("Empty list.\n");
		exit(0);
	}

	linked_node * pnode = list;
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

linked_node * LinkedListNoHeadLocate(linked_list * list, elem_type elem)
{
	if (LinkedListNoHeadEmpty(list)) {
		printf("Empty list.\n");
		return NULL;
	}

	linked_node * pnode = list;

	while (pnode->elem != elem && pnode->next)
		pnode = pnode->next;

	if (pnode->elem == elem)
		return pnode;

	printf("Not find.\n");
	return NULL;
}

linked_node * LinkedListNoHeadFormer(linked_list * list, linked_list * locat)
{
	if (list == locat) {
		printf("No former.\n");
		return NULL;
	}

	linked_node * former = list;
	linked_node * pnode = former->next;


	while (pnode != locat && pnode->next) {
		former = pnode;
		pnode = pnode->next;
	}
	if (pnode == locat)
		return former;

	printf("Illegal input.\n");
	return NULL;
}

linked_node * LinkedListNoHeadLatter(linked_list * list, elem_type elem)
{
	if (LinkedListNoHeadEmpty(list)) {
		printf("Empty list.\n");
		return NULL;
	}

	linked_node * pnode = list;

	while (pnode->elem != elem && pnode->next) {
		pnode = pnode->next;
	}
	if (pnode->elem == elem) {
		if (!pnode->next)
			printf("No latter.\n");
		return pnode->next;
	}

	printf("Illegal input.\n");
	return NULL;
}

void LinkedListNoHeadInsert(linked_list * list, linked_node * locat, elem_type elem)
{
	linked_node * pnode = (linked_node *) malloc(sizeof(linked_node));
	if (!pnode) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}

	pnode->elem = elem;
	pnode->next = locat->next;
	locat->next = pnode;
}

void LinkedListNoHeadDelete(linked_list * list, linked_node * locat)
{
	linked_node * former;
	if (list == locat)
		former = list;
	else
		former = LinkedListNoHeadFormer(list, locat);

	former->next = locat->next;

	free(locat);
}

bool LinkedListNoHeadEmpty(linked_list * list)
{
	if (list)
		return false;
	else
		return true;
}

void LinkedListNoHeadDestroy(linked_list * list)
{
	if (LinkedListNoHeadEmpty(list))
		return;

	linked_node * pnode = list;
	linked_node * latter;

	while (pnode->next) {
		latter = pnode->next;
		free(pnode);
		pnode = latter;
	}
	free(pnode);

	list = NULL;
}

void LinkedListNoHeadAdd(linked_list ** list, elem_type elem)
{
	if (LinkedListNoHeadEmpty(*list) || elem <= (*list)->elem) {
		linked_node * pnode = (linked_node *) malloc(sizeof(linked_node));
		if (!pnode) {
			printf("Fail to allocate memory.\n");
			exit(0);
		}
		pnode->elem = elem;
		pnode->next = (*list);
		(*list) = pnode;
		return;
	}

	linked_node * pnode = (*list);

	while (elem > pnode->elem) {
		if (!pnode->next) {
			LinkedListNoHeadInsert((*list), pnode, elem);
			return;
		}
		pnode = pnode->next;
	}

	linked_node * former = LinkedListNoHeadFormer((*list), pnode);
	LinkedListNoHeadInsert((*list), former, elem);
	return;
}

void LinkedListNoHeadCat(linked_list * list1, linked_list * list2)
{
	if (LinkedListNoHeadEmpty(list1)) {
		list1 = list2;
		return;
	}

	linked_node * pnode = list1;

	while (pnode->next)
		pnode = pnode->next;
	pnode->next = list2;
}

void LinkedListNoHeadUnion(linked_list * list1, linked_list * list2, linked_list ** list3)
{
	if (LinkedListNoHeadEmpty(list1)) {
		(*list3) = list2;
		return;
	}
	if (LinkedListNoHeadEmpty(list2)) {
		(*list3) = list1;
		return;
	}

	linked_node * pnode1 = list1;
	linked_node * pnode2 = list2;
	LinkedListNoHeadDestroy(*list3);
	(*list3) = LinkedListNoHeadInit();

	while (pnode1 && pnode2) {
		if (pnode1->elem <= pnode2->elem) {
			LinkedListNoHeadAdd(list3, pnode1->elem);
			pnode1 = pnode1->next;
		}
		else {
			LinkedListNoHeadAdd(list3, pnode2->elem);
			pnode2 = pnode2->next;
		}
	}
	while (pnode1) {
		LinkedListNoHeadAdd(list3, pnode1->elem);
		pnode1 = pnode1->next;
	}
	while (pnode2) {
		LinkedListNoHeadAdd(list3, pnode2->elem);
		pnode2 = pnode2->next;
	}
}

void SeqToLinkedNoHead(seq_list * s_list, linked_list ** l_list)
{
	LinkedListNoHeadDestroy(*l_list);
	(*l_list) = LinkedListNoHeadInit();
	int num = s_list->num_elem;
	while (num) {
		LinkedListNoHeadAdd(l_list, s_list->elem[num - 1]);
		num--;
	}
}
