#include "linked_list_head.h"

//在指定链表结点后插入新结点
void LinkedListHeadInsert(linked_node * locat, int out, int in, int weight);

linked_list LinkedListHeadInit(void)
{
	linked_list plist;
	plist = (linked_list ) malloc(sizeof(linked_node));
	if (!plist) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}
	plist->next_path = NULL;

	return plist;
}

void LinkedListHeadAdd(linked_list list, int out, int in, int weight)
{
	if (LinkedListHeadEmpty(list)) {
		LinkedListHeadInsert(list, out, in, weight);
		return;
	}

	linked_node * former = list;
	linked_node * pnode = list->next_path;

	while (pnode != NULL && weight > pnode->weight) {
		former = former->next_path;
		pnode = pnode->next_path;
	}

	LinkedListHeadInsert(former, out, in, weight);
}

void LinkedListHeadInsert(linked_node * locat, int out, int in, int weight)
{
	linked_node * pnode = (linked_node *) malloc(sizeof(linked_node));
	if (!pnode) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}
	pnode->out = out;
	pnode->in = in;
	pnode->weight = weight;
	pnode->next_path = locat->next_path;
	locat->next_path = pnode;
}

void LinkedListHeadDelete(linked_list list, linked_node * locat)
{
	if (locat == list) {
		printf("Can't delete the head node.\n");
		return;
	}

	linked_node * former = list;
	linked_node * pnode = former->next_path;

	while (pnode != locat) {
		former = pnode;
		pnode = pnode->next_path;
	}

	former->next_path = locat->next_path;
	free(locat);
}

bool LinkedListHeadEmpty(linked_list list)
{
	if (list->next_path)
		return false;
	else
		return true;
}

void LinkedListHeadDestroy(linked_list * list)
{
	if (*list) {
		linked_node * pnode = (*list);
		linked_node * latter;

		while (pnode->next_path) {
			latter = pnode->next_path;
			free(pnode);
			pnode = latter;
		}
		free(pnode);

		(*list) = NULL;
	}
}
