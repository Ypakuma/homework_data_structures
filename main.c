#include "queue\cir_queue\cir_queue.h"

int main(void)
{
	cir_queue queue;
	queue = CirQueueInit();
	bool ans;
	ans = CirQueueEmpty(queue);
	CirQueueEnter(queue, 1);
	ans = CirQueueEmpty(queue);
	CirQueueEnter(queue, 2);
	CirQueueEnter(queue, 3);
	CirQueueEnter(queue, 4);
	CirQueueEnter(queue, 5);
	CirQueueEnter(queue, 6);
	CirQueueEnter(queue, 7);
	CirQueueEnter(queue, 8);
	CirQueueEnter(queue, 9);
	CirQueueEnter(queue, 10);
	ans = CirQueueFull(queue);


	int a;
	a = CirQueueExit(queue);
	ans = CirQueueFull(queue);
	a = CirQueueExit(queue);
	a = CirQueueExit(queue);


	CirQueueClear(queue);
	ans = CirQueueEmpty(queue);

	CirQueueDestroy(&queue);

	return 0;
}
