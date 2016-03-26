#include "list\linked_list_noHead\linked_list_noHead.h"
#include "list\seq_list\seq_list.h"

int main(void)
{
	linked_list * list, * list2, * list3;
	seq_list *slist;
	slist = SeqListInit();
	SeqListAdd(slist, 12);
	SeqListAdd(slist, 24);
	SeqListAdd(slist, 37);
	SeqListAdd(slist, 11);
	SeqListAdd(slist, 16);
	SeqListAdd(slist, 50);
	SeqListAdd(slist, 5);


	list = LinkedListNoHeadInit();
	list2 = LinkedListNoHeadInit();
	list3 = LinkedListNoHeadInit();


	LinkedListNoHeadAdd(&list, 5);
	LinkedListNoHeadAdd(&list, 78);
	LinkedListNoHeadAdd(&list, 26);
	LinkedListNoHeadAdd(&list, 35);

	SeqToLinkedNoHead(slist, &list);
	SeqListDestroy(slist);
	
	int ans = LinkedListNoHeadLength(list);
	ans = LinkedListNoHeadGet(list, 3);
	linked_node * node = LinkedListNoHeadLocate(list, 78);
	node = LinkedListNoHeadLatter(list, 26);
	node = LinkedListNoHeadLatter(list, 78);
	
	LinkedListNoHeadInsert(list, list->next->next, 99);
	LinkedListNoHeadDelete(list, list->next->next->next);


	LinkedListNoHeadAdd(&list, 5);
	LinkedListNoHeadAdd(&list, 78);
	LinkedListNoHeadAdd(&list, 26);
	LinkedListNoHeadAdd(&list, 35);
	LinkedListNoHeadDestroy(list);

	list = LinkedListNoHeadInit();


	LinkedListNoHeadAdd(&list, 56);
	LinkedListNoHeadAdd(&list, 53);
	LinkedListNoHeadAdd(&list, 78);
	LinkedListNoHeadAdd(&list, 26);
	LinkedListNoHeadAdd(&list, 35);

	LinkedListNoHeadAdd(&list2, 115);
	LinkedListNoHeadAdd(&list2, 154);
	LinkedListNoHeadAdd(&list2, 178);
	LinkedListNoHeadAdd(&list2, 216);
	LinkedListNoHeadAdd(&list2, 315);

	LinkedListNoHeadUnion(list, list2, &list3);
	LinkedListNoHeadDestroy(list);
	LinkedListNoHeadDestroy(list2);
	LinkedListNoHeadDestroy(list3);
	


	return 0;
}
