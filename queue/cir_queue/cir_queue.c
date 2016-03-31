#include "cir_queue.h"

cir_queue CirQueueInit(void)
{
	cir_queue pqueue = (cir_queue) malloc(sizeof(struct queue));

	pqueue->front = 0;
	pqueue->rear = 0;
	//leave the last element as a symbol to judge the queue is full or empty, and the element don't storage data.
	pqueue->elem = (elem_type*) malloc(sizeof(elem_type) * (MAX_ELEM + 1));
	
	return pqueue;
}

bool CirQueueEmpty(cir_queue queue)
{
	return queue->front == queue->rear;
}

bool CirQueueFull(cir_queue queue)
{
	return (queue->rear + 1) % MAX_ELEM == queue->front;
}

bool CirQueueEnter(cir_queue queue, elem_type elem)
{
	if (CirQueueFull(queue)) {
		printf("Full queue.\n");
		return false;
	}

	queue->elem[queue->rear++] = elem;
	return true;
}

elem_type CirQueueExit(cir_queue queue)
{
	if (CirQueueEmpty(queue)) {
		printf("Empty queue.\n");
		exit(0);
	}

	return queue->elem[queue->front++];
}

void CirQueueClear(cir_queue queue)
{
	queue->front = 0;
	queue->rear = 0;
}

void CirQueueDestroy(cir_queue * queue)
{
	if (*queue) {
		free((*queue)->elem);
		free(*queue);
		(*queue) = NULL;
	}
}
