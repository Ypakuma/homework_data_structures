#include "linked_list_nohead.h"

linked_list LinkedListNoHeadInit(void)
{
	return NULL;
}

int LinkedListNoHeadLength(linked_list list)
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

linked_node * LinkedListNoHeadGet(linked_list list, int index)
{
	if (LinkedListNoHeadEmpty(list)) {
		printf("Empty list.\n");
		return NULL;
	}

	linked_node * pnode = list;
	int num = 1;

	while (num < index && pnode->next) {
		pnode = pnode->next;
		num++;
	}
	if (num == index)
		return pnode;

	printf("Input too much.\n");
	return NULL;
}

linked_node * LinkedListNoHeadLocate(linked_list list, elem_type elem)
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

linked_node * LinkedListNoHeadFormer(linked_list * list, linked_node * locat)
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

linked_node * LinkedListNoHeadLatter(linked_list list, elem_type elem)
{
	if (LinkedListNoHeadEmpty(list)) {
		printf("Empty list.\n");
		return NULL;
	}

	linked_node * pnode = list;
	linked_node * latter = list->next;

	while (pnode->elem != elem && latter) {
		pnode = pnode->next;
	}
	if (pnode->elem == elem) {
		if (!latter)
			printf("No latter.\n");
		return latter;
	}

	printf("Illegal input.\n");
	return NULL;
}

bool LinkedListNoHeadInsert(linked_node * locat, elem_type elem)
{
	linked_node * pnode = (linked_node *) malloc(sizeof(linked_node));
	if (!pnode) {
		printf("Fail to allocate memory.\n");
		return false;
	}

	pnode->elem = elem;
	pnode->next = locat->next;
	locat->next = pnode;

	return true;
}

bool LinkedListNoHeadDelete(linked_list list, linked_node * locat)
{
	if (list == locat) {
		list = locat->next;
		free(locat);
		return true;
	}

	linked_node * former;
	former = LinkedListNoHeadFormer(list, locat);
	if (former == NULL) {
		printf("can not delete.\n");
		return false;
	}
	former->next = locat->next;
	free(locat);
}

bool LinkedListNoHeadEmpty(linked_list list)
{
	if (list)
		return false;
	else
		return true;
}

void LinkedListNoHeadDestroy(linked_list * list)
{
	if (LinkedListNoHeadEmpty(*list))
		return;

	linked_node * pnode = (*list);

	while (pnode->next) {
		linked_node * latter = pnode->next;
		free(pnode);
		pnode = latter;
	}
	free(pnode);

	*list = NULL;
}

void LinkedListNoHeadAdd(linked_list * list, elem_type elem)
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

	linked_node * former = *list;
	linked_node * pnode = former->next;

	while (pnode) {
		if (elem <= pnode->elem) {
			LinkedListNoHeadInsert(former, elem);
			return;
		}
		former = pnode;
		pnode = former->next;
	}

	LinkedListNoHeadInsert(former, elem);
	return;
}

void LinkedListNoHeadCat(linked_list * list1, linked_list * list2)
{
	if (LinkedListNoHeadEmpty(*list1)) {
		*list1 = *list2;
		*list2 = NULL;
		return;
	}

	linked_node * pnode = *list1;
	while (pnode->next)
		pnode = pnode->next;
	pnode->next = *list2;
	*list2 = NULL;
}

void LinkedListNoHeadUnion(linked_list * list1, linked_list * list2)
{
	if (LinkedListNoHeadEmpty(*list1)) {
		*list1 = *list2;
		*list2 = NULL;
		return;
	}
	if (LinkedListNoHeadEmpty(*list2))
		return;

	linked_node * former1 = *list1;
	linked_node * pnode1 = former1->next;
	linked_node * pnode2 = *list2;

	while (pnode1 && pnode2) {
		if (pnode1->elem < pnode2->elem) {
			former1 = pnode1;
			pnode1 = former1->next;
		}
		else {
			linked_node * ptemp = pnode2->next;
			pnode2->next = pnode1->next;
			pnode1->next = pnode2;
			pnode2 = ptemp;
		}
	}
	if (pnode2)
		former1->next = pnode2;
	*list2 = NULL;
}

void SeqToLinkedNoHead(seq_list * s_list, linked_list * l_list)
{
	LinkedListNoHeadDestroy(l_list);

	int num = s_list->num_elem;
	while (num) {
		LinkedListNoHeadAdd(l_list, s_list->elem[num - 1]);
		num--;
	}
}
