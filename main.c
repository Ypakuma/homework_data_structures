#include "list\linked_list_Head\linked_list_Head.h"
#include "list\seq_list\seq_list.h"

int main(void)
{
	linked_list * list, * list2, * list3;

	seq_list *slist;

	slist = SeqListInit();
	SeqListAdd(slist, 15);
	SeqListAdd(slist, 78);
	SeqListAdd(slist, 25);
	SeqListAdd(slist, 5);
	SeqListAdd(slist, 8);

	list = LinkedListHeadInit();
	list2 = LinkedListHeadInit();
	list3 = LinkedListHeadInit();

	SeqToLinkedHead(slist, list);
	SeqListDestroy(slist);
	LinkedListHeadAdd(list, 5);
	LinkedListHeadAdd(list, 78);
	LinkedListHeadAdd(list, 26);
	LinkedListHeadAdd(list, 35);

	
	int ans = LinkedListHeadLength(list);
	ans = LinkedListHeadGet(list, 3);
	linked_node * node = LinkedListHeadLocate(list, 78);
	node = LinkedListHeadLatter(list, 26);
	node = LinkedListHeadLatter(list, 78);
	
	LinkedListHeadInsert(list, list->next->next, 99);
	LinkedListHeadDelete(list, list->next->next->next);


	LinkedListHeadAdd(list, 5);
	LinkedListHeadAdd(list, 78);
	LinkedListHeadAdd(list, 26);
	LinkedListHeadAdd(list, 35);
	LinkedListHeadDestroy(list);

	list = LinkedListHeadInit();


	LinkedListHeadAdd(list, 56);
	LinkedListHeadAdd(list, 53);
	LinkedListHeadAdd(list, 78);
	LinkedListHeadAdd(list, 26);
	LinkedListHeadAdd(list, 35);

	LinkedListHeadAdd(list2, 115);
	LinkedListHeadAdd(list2, 154);
	LinkedListHeadAdd(list2, 178);
	LinkedListHeadAdd(list2, 216);
	LinkedListHeadAdd(list2, 315);

	LinkedListHeadUnion(list, list2, list3);
	LinkedListHeadDestroy(list);
	LinkedListHeadDestroy(list2);
	LinkedListHeadDestroy(list3);
	


	return 0;
}
