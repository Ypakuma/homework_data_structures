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

void LinkedListHeadDestroy(linked_list * list)
{
	if (*list) {
		LinkedListHeadClear(*list);
		free(*list);
		(*list) = NULL;
	}
}

void LinkedListHeadAdd(linked_list list, linked_list_head_elemtype elem)
{
	if (LinkedListHeadEmpty(list)) {
		linked_node * pnode = (linked_node *) malloc(sizeof(linked_node));
		if (!pnode) {
			printf("Fail to allocate memory.\n");
			exit(0);
		}
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
