#include "queue\linked_queue\linked_queue.h"

int main(void)
{
	linked_queue queue;
	queue = LinkedQueueInit();
	bool ans;
	ans = LinkedQueueEmpty(queue);
	LinkedQueueEnter(queue, 1);
	ans = LinkedQueueEmpty(queue);
	LinkedQueueEnter(queue, 2);
	LinkedQueueEnter(queue, 3);
	LinkedQueueEnter(queue, 4);
	LinkedQueueEnter(queue, 5);
	LinkedQueueEnter(queue, 6);
	LinkedQueueEnter(queue, 7);
	LinkedQueueEnter(queue, 8);
	LinkedQueueEnter(queue, 9);
	LinkedQueueEnter(queue, 10);


	int a;
	a = LinkedQueueExit(queue);
	a = LinkedQueueExit(queue);
	a = LinkedQueueExit(queue);


	ans = LinkedQueueEmpty(queue);

	LinkedQueueDestroy(&queue);

	return 0;
}
