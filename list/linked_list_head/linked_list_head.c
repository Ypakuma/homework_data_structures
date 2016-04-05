#include "linked_list_head.h"

linked_list LinkedListHeadInit(void)
{
	linked_list plist;
	plist = (linked_list ) malloc(sizeof(linked_node));
	if (!plist) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}
	plist->next = NULL;

	return plist;
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

linked_node * LinkedListHeadGet(linked_list list, int index)
{
	if (LinkedListHeadEmpty(list)) {
		printf("Empty list.\n");
		return NULL;
	}

	linked_node * pnode = list->next;
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

linked_node * LinkedListHeadLocate(linked_list list, linked_list_head_elemtype elem)
{
	if (LinkedListHeadEmpty(list)) {
		printf("Empty list.\n");
		return NULL;
	}

	linked_node * pnode = list->next;

	while (pnode->elem != elem && pnode->next) 
		pnode = pnode->next;

	if (pnode->elem == elem)
		return pnode;
	printf("Not find.\n");
	return NULL;
}

linked_node * LinkedListHeadFormer(linked_list list, linked_node * locat)
{
	if (LinkedListHeadEmpty(list)) {
		printf("Empty list.\n");
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

linked_node * LinkedListHeadLatter(linked_list list, linked_list_head_elemtype elem)
{
	if (LinkedListHeadEmpty(list)) {
		printf("Empty list.\n");
		return NULL;
	}
	
	linked_node * pnode = list->next;

	while (pnode->elem != elem && pnode->next)
		pnode = pnode->next;

	if (pnode->elem == elem) {
		if (!pnode->next)
			printf("No latter.\n");
		return pnode->next;
	}

	printf("Illegal input.\n");
	return NULL;
}

void LinkedListHeadInsert(linked_node * locat, linked_list_head_elemtype elem)
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

void LinkedListHeadDelete(linked_list list, linked_node * locat)
{
	if (locat == list) {
		printf("Can't delete the head node.\n");
		return;
	}
	linked_node * former;
	former = LinkedListHeadFormer(list, locat);

	if (former) {
		former->next = locat->next;
		free(locat);
	}
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
	if (list) {
		LinkedListHeadClear(list);
		free(list);
		list->next = NULL;
	}
}

void LinkedListHeadAdd(linked_list list, linked_list_head_elemtype elem)
{
	if (LinkedListHeadEmpty(list)) {
		linked_node * pnode = (linked_node *) malloc(sizeof(linked_node));
		pnode->elem = elem;
		pnode->next = NULL;
		list->next = pnode;
		return;
	}

	linked_node * pnode = list->next;

	while (elem > pnode->elem) {
		if (!pnode->next) {
			LinkedListHeadInsert(pnode, elem);
			return;
		}
		pnode = pnode->next;
	}

	linked_node * former;
	former = LinkedListHeadFormer(list, pnode);
	LinkedListHeadInsert(former, elem);
}

void LinkedListHeadCat(linked_list * list1, linked_list * list2)
{
	linked_node * pnode = (*list1);

	while (pnode->next)
		pnode = pnode->next;
	pnode->next = (*list2)->next;
	free(*list2);
}

void LinkedListHeadUnion(linked_list * list1, linked_list * list2)
{
	linked_node * former1 = (*list1);
	linked_node * pnode1 = (*list1)->next;
	linked_node * pnode2 = (*list2)->next;

	while (pnode1 && pnode2) {
		if (pnode1->elem > pnode2->elem) {
			linked_node * ptemp = pnode2->next;
			pnode2->next = pnode1;
			former1->next = pnode2;
			pnode2 = ptemp;
			former1 = former1->next;
		}
		else {
			pnode1 = pnode1->next;
			former1 = former1->next;
		}
	}
	if (pnode2)
		former1->next = pnode2;
	free(*list2);
	list2 = NULL;
}

void SeqToLinkedHead(seq_list s_list, linked_list l_list)
{
	int num = s_list->num_elem;
	while (num) {
		LinkedListHeadAdd(l_list, s_list->elem[num - 1]);
		num--;
	}
}
