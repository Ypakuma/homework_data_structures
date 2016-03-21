#include "linked_list_head.h"

int main(void)
{
	linked_list list, list2, list3;

	LinkedListHeadInit(&list);
	LinkedListHeadInit(&list2);
	LinkedListHeadInit(&list3);

	LinkedListHeadAdd(list, 5);
	LinkedListHeadAdd(list, 78);
	LinkedListHeadAdd(list, 26);
	LinkedListHeadAdd(list, 35);

	int ans = LinkedListHeadLength(list);
	ans = LinkedListHeadGet(list, 3);
	linked_node* node =  LinkedListHeadLocate(list, 78);
	ans = LinkedListHeadIndex(list, list->next->next);
	node = LinkedListHeadLatter(list, 26);
	node = LinkedListHeadLatter(list, 78);

	LinkedListHeadInsert(list, list->next->next, 99);
	LinkedListHeadDelete(list, list->next);


	LinkedListHeadClear(list);
	LinkedListHeadAdd(list, 5);
	LinkedListHeadAdd(list, 78);
	LinkedListHeadAdd(list, 26);
	LinkedListHeadAdd(list, 35);
	LinkedListHeadDestroy(list);

	LinkedListHeadInit(&list);
	

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