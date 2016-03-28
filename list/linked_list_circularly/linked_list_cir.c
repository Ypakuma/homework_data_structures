#include "linked_list_cir.h"

cir_list LinkedListCirInit(void)
{
	cir_list plist = (cir_list*) malloc(sizeof(struct list));
	if (!plist) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}

	cir_node * pnode = (cir_node*) malloc(sizeof(cir_node));
	if (!pnode) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}

	plist->head = pnode;
	plist->tail = pnode;
	pnode->next = pnode;

	return plist;
}

bool LinkedListCirEmpty(cir_list list)
{
	return list->head == list->tail;
}

void LinkedListCirInsert(cir_list list, cir_node * locat, elem_type elem)
{
	cir_node * pnode = (cir_node *) malloc(sizeof(cir_node));
	if (!pnode) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}

	pnode->elem = elem;
	pnode->next = locat->next;
	locat->next = pnode;

	if (list->tail == locat)
		list->tail = pnode;
}

void LinkedListCirAdd(cir_list list, elem_type elem)
{
	if (LinkedListCirEmpty(list)) {
		LinkedListCirInsert(list, list->head, elem);
		return;
	}

	cir_node * pnode = list->head->next;
	cir_node * former = list->head;

	while (former != list->tail && elem > pnode->elem) {
		former = pnode;
		pnode = pnode->next;		
	}
	LinkedListCirInsert(list, former, elem);
}

void LinkedListCirClear(cir_list list)
{
	cir_node * pnode = list->head->next;
	cir_node * latter = pnode->next;

	while (latter != list->head) {
		free(pnode);
		pnode = latter;
		latter = pnode->next;
	}
	free(pnode);
	latter->next = latter;
	list->tail = latter;
}

void LinkedListCirDestroy(cir_list list)
{
	if(!LinkedListCirEmpty(list))
		LinkedListCirClear(list);

	free(list->head);

	free(list);
	list = NULL;
}
