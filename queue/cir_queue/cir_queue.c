#include "cir_queue.h"

cir_queue CirQueueInit(void)
{
	cir_queue pqueue = (cir_queue) malloc(sizeof(struct queue));

	pqueue->front = 0;
	pqueue->count = 0;
	pqueue->elem = (elem_type*) malloc(sizeof(elem_type) * MAX_ELEM);
	
	return pqueue;
}

bool CirQueueEmpty(cir_queue queue)
{
	return !(queue->count);
}

bool CirQueueFull(cir_queue queue)
{
	return queue->count == MAX_ELEM;
}

bool CirQueueEnter(cir_queue queue, elem_type elem)
{
	if (CirQueueFull(queue)) {
		printf("Full queue.\n");
		return false;
	}

	int index = (queue->front + queue->count) % MAX_ELEM;
	queue->elem[index] = elem;
	queue->count++;
	return true;
}

elem_type CirQueueExit(cir_queue queue)
{
	if (CirQueueEmpty(queue)) {
		printf("Empty queue.\n");
		exit(0);
	}

	queue->count--;
	elem_type elem =  queue->elem[queue->front];
	queue->front = (queue->front + 1) % MAX_ELEM;

	return elem;
}

void CirQueueClear(cir_queue queue)
{
	queue->front = 0;
	queue->count = 0;
}

void CirQueueDestroy(cir_queue * queue)
{
	if (*queue) {
		free((*queue)->elem);
		free(*queue);
		(*queue) = NULL;
	}
}
