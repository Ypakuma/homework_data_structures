#include "list\linked_list_circularly\linked_list_cir.h"

int main(void)
{
	cir_list_t list_t;
	//cir_list_t list2;

	seq_list *slist;

	slist = SeqListInit();
	SeqListAdd(slist, 15);
	SeqListAdd(slist, 78);
	SeqListAdd(slist, 25);
	SeqListAdd(slist, 5);
	SeqListAdd(slist, 8);

	list_t = LinkedListCirInit();
	//list2 = LinkedListCirInit();

	SeqToLinkedCir(slist, &list_t);
	SeqListDestroy(slist);
	//LinkedListCirAdd(&list_t, 5);
	//LinkedListCirAdd(&list_t, 78);
	//LinkedListCirAdd(&list_t, 26);
	//LinkedListCirAdd(&list_t, 35);

	//LinkedListCirClear(&list_t);

	//LinkedListCirDestroy(list_t);
	//list_t = LinkedListCirInit();


	//int ans = LinkedListCirLength(list_t);
	//cir_node * node = LinkedListCirGet(list_t, 3);
	//node = LinkedListCirLocate(list_t, 78);
	//node = LinkedListCirFormer(list_t, node);
	//node = LinkedListCirLatter(list_t, 26);
	//node = LinkedListCirLatter(list_t, 78);

	//LinkedListCirInsert(&list_t, list_t->next->next, 99);
	//LinkedListCirDelete(&list_t, list_t->next->next->next);


	//LinkedListCirAdd(&list_t, 5);
	//LinkedListCirAdd(&list_t, 78);
	//LinkedListCirAdd(&list_t, 26);
	//LinkedListCirAdd(&list_t, 35);
	//LinkedListCirDestroy(list_t);

	//list_t = LinkedListCirInit();


	//LinkedListCirAdd(&list_t, 56);
	//LinkedListCirAdd(&list2, 53);
	//LinkedListCirAdd(&list_t, 78);
	//LinkedListCirAdd(&list2, 26);
	//LinkedListCirAdd(&list_t, 35);

	//LinkedListCirAdd(&list2, 115);
	//LinkedListCirAdd(&list2, 154);
	//LinkedListCirAdd(&list_t, 178);
	//LinkedListCirAdd(&list2, 346);
	//LinkedListCirAdd(&list_t, 255);

	//LinkedListCirUnion(&list_t, &list2);
	//LinkedListCirDestroy(list_t);
	//LinkedListCirDestroy(list2);



	return 0;
}
