#include "list\linked_list_NoHead\linked_list_NoHead.h"
#include "list\seq_list\seq_list.h"

int main(void)
{
	linked_list list, list2, list3;

	seq_list *slist;

	slist = SeqListInit();
	SeqListAdd(slist, 15);
	SeqListAdd(slist, 78);
	SeqListAdd(slist, 25);
	SeqListAdd(slist, 5);
	SeqListAdd(slist, 8);

	list = LinkedListNoHeadInit();
	list2 = LinkedListNoHeadInit();
	list3 = LinkedListNoHeadInit();

	SeqToLinkedNoHead(slist, &list);
	SeqListDestroy(slist);
	LinkedListNoHeadAdd(&list, 5);
	LinkedListNoHeadAdd(&list, 78);
	LinkedListNoHeadAdd(&list, 26);
	LinkedListNoHeadAdd(&list, 35);

	

	
	int ans = LinkedListNoHeadLength(list);
	linked_node * node = LinkedListNoHeadGet(list, 3);
	node = LinkedListNoHeadLocate(list, 78);
	node = LinkedListNoHeadFormer(list, node);
	node = LinkedListNoHeadLatter(list, 26);
	node = LinkedListNoHeadLatter(list, 78);
	
	LinkedListNoHeadInsert(list->next->next, 99);
	LinkedListNoHeadDelete(list, list->next->next->next);


	LinkedListNoHeadAdd(&list, 5);
	LinkedListNoHeadAdd(&list, 78);
	LinkedListNoHeadAdd(&list, 26);
	LinkedListNoHeadAdd(&list, 35);
	LinkedListNoHeadDestroy(&list);

	//list = LinkedListNoHeadInit();


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

	LinkedListNoHeadCat(&list, &list2);
	LinkedListNoHeadDestroy(&list);
	LinkedListNoHeadDestroy(&list2);
	LinkedListNoHeadDestroy(&list3);
	


	return 0;
}
