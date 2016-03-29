#include "linked_list_cir.h"

cir_list_t LinkedListCirInit(void)
{
	cir_node * pnode = (cir_node*) malloc(sizeof(cir_node));
	if (!pnode) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}

	cir_list_t plist_tail = pnode;
	pnode->next = pnode;

	return plist_tail;
}

bool LinkedListCirEmpty(cir_list_t list_t)
{
	return list_t->next == list_t;
}

void LinkedListCirInsert(cir_list_t * list_t, cir_node * locat, elem_type elem)
{
	cir_node * pnode = (cir_node *) malloc(sizeof(cir_node));
	if (!pnode) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}

	pnode->elem = elem;
	pnode->next = locat->next;
	locat->next = pnode;

	if ((*list_t) == locat)
		(*list_t) = pnode;
}

void LinkedListCirAdd(cir_list_t * list_t, elem_type elem)
{
	if (LinkedListCirEmpty(*list_t)) {
		LinkedListCirInsert(list_t, (*list_t), elem);
		return;
	}

	cir_node * pnode = (*list_t)->next->next;
	cir_node * former = (*list_t)->next;

	while (former != (*list_t) && elem > pnode->elem) {
		former = pnode;
		pnode = pnode->next;		
	}
	LinkedListCirInsert(list_t, former, elem);
}

void LinkedListCirClear(cir_list_t * list_t)
{
	cir_node * pnode = (*list_t)->next->next;
	cir_node * latter = pnode->next;

	while (latter != (*list_t)->next) {
		free(pnode);
		pnode = latter;
		latter = pnode->next;
	}
	free(pnode);
	latter->next = latter;
	(*list_t) = latter;
}

void LinkedListCirDestroy(cir_list_t list_t)
{
	if (list_t) {
		if (!LinkedListCirEmpty(list_t))
			LinkedListCirClear(&list_t);

		free(list_t);
	}
}

cir_node * LinkedListCirFormer(cir_list_t list_t, cir_node * locat)
{
	if (LinkedListCirEmpty(list_t)) {
		printf("Empty list.\n");
		return NULL;
	}

	cir_node * former = list_t->next;

	while (former->next != locat && former != list_t)
		former = former->next;
	if (former->next == locat)
		return former;
	else {
		printf("No former.\n");
		return NULL;
	}
}

cir_node * LinkedListCirLatter(cir_list_t list_t, elem_type elem)
{
	if (LinkedListCirEmpty(list_t)) {
		printf("Empty list.\n");
		return NULL;
	}

	cir_node * pnode = list_t->next->next;

	while (pnode->elem != elem && pnode != list_t)
		pnode = pnode->next;

	if (pnode->elem == elem)
		return pnode->next;

	printf("Illegal input.\n");
	return NULL;
}

void LinkedListCirDelete(cir_list_t * list_t, cir_node * locat)
{
	if (LinkedListCirEmpty(*list_t)) {
		printf("Empty list.\n");
		return;
	}
	if (locat == (*list_t)->next) {
		printf("Can't delete the head node.\n");
		return;
	}

	cir_node * former = LinkedListCirFormer(*list_t, locat);

	if (former) {
		former->next = locat->next;
		free(locat);

		if (locat == (*list_t))
			(*list_t) = former;
	}
}

cir_node * LinkedListCirGet(cir_list_t list_t, int index)
{
	if (LinkedListCirEmpty(list_t)) {
		printf("Empty list.\n");
		return NULL;
	}

	cir_node * pnode = list_t->next->next;
	int num = 1;

	while (num < index && pnode != list_t) {
		pnode = pnode->next;
		num++;
	}
	if (num == index)
		return pnode;
	printf("Input too much.\n");
	return NULL;
}

cir_node * LinkedListCirLocate(cir_list_t list_t, elem_type elem)
{
	if (LinkedListCirEmpty(list_t)) {
		printf("Empty list.\n");
		return NULL;
	}

	cir_node * pnode = list_t->next->next;

	while (pnode->elem != elem && pnode != list_t)
		pnode = pnode->next;

	if (pnode->elem == elem)
		return pnode;
	printf("Not find.\n");
	return NULL;
}

int LinkedListCirLength(cir_list_t list_t)
{
	cir_node * pnode = list_t->next;
	int num = 0;

	while (pnode != list_t) {
		num++;
		pnode = pnode->next;
	}

	return num;
}

void LinkedListCirCat(cir_list_t * list1_t, cir_list_t * list2_t)
{
	cir_node * pnode = (*list2_t)->next;

	(*list2_t)->next = (*list1_t)->next;
	(*list1_t)->next = pnode->next;
	(*list1_t) = (*list2_t);

	free(pnode);
	(*list2_t) = NULL;
}

void LinkedListCirUnion(cir_list_t * list1_t, cir_list_t * list2_t)
{
	cir_node * former1 = (*list1_t)->next;
	cir_node * pnode1 = former1->next;
	cir_node * pnode2 = (*list2_t)->next->next;
	cir_node * head2 = (*list2_t)->next;


	while (pnode1 != (*list1_t)->next && pnode2 != head2) {
		if (pnode1->elem > pnode2->elem) {
			cir_node * ptemp = pnode2->next;
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
	(*list1_t) = pnode1;

	if (pnode2 != head2) {
		former1->next = pnode2;
		(*list2_t)->next = pnode1;
		(*list1_t) = (*list2_t);
	}
	free(head2);
	(*list2_t) = NULL;
}

void SeqToLinkedCir(seq_list * s_list, cir_list_t * l_list_t)
{
	int num = s_list->num_elem;
	while (num) {
		LinkedListCirAdd(l_list_t, s_list->elem[num - 1]);
		num--;
	}
}
