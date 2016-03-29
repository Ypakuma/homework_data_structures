#include "list\linked_list_circularly_double\linked_list_cir_doub.h"
#include "list\seq_list\seq_list.h"

int main(void)
{
	cir_doub_list list;
	cir_doub_list list2;

	seq_list *slist;

	slist = SeqListInit();
	SeqListAdd(slist, 15);
	SeqListAdd(slist, 78);
	SeqListAdd(slist, 25);
	SeqListAdd(slist, 5);
	SeqListAdd(slist, 8);

	list = LinkedListCirDoubInit();
	//list2 = LinkedListCirDoubInit();

	SeqToLinkedCirDoub(slist, list);
	SeqListDestroy(slist);
	//LinkedListCirDoubAdd(list, 5);
	//LinkedListCirDoubAdd(list, 78);
	//LinkedListCirDoubAdd(list, 26);
	//LinkedListCirDoubAdd(list, 35);

	//LinkedListCirDoubClear(list);

	//LinkedListCirDoubDestroy(list);
	//list = LinkedListCirDoubInit();


	//int ans = LinkedListCirDoubLength(list);
	//cir_doub_node * node = LinkedListCirDoubGet(list, 3);
	//node = LinkedListCirDoubLocate(list, 78);

	//LinkedListCirDoubInsert(list->next->next, 99);
	//LinkedListCirDoubDelete(list, list->next->next->next);


	//LinkedListCirDoubAdd(list, 56);
	//LinkedListCirDoubAdd(list2, 53);
	//LinkedListCirDoubAdd(list, 78);
	//LinkedListCirDoubAdd(list2, 26);
	//LinkedListCirDoubAdd(list, 35);

	//LinkedListCirDoubAdd(list2, 115);
	//LinkedListCirDoubAdd(list2, 154);
	//LinkedListCirDoubAdd(list, 178);
	//LinkedListCirDoubAdd(list2, 346);
	//LinkedListCirDoubAdd(list, 255);

	//LinkedListCirDoubUnion(list, &list2);
	//LinkedListCirDoubCat(list, &list2);
	//
	//LinkedListCirDoubDestroy(list);
	//LinkedListCirDoubDestroy(list2);



	return 0;
}
