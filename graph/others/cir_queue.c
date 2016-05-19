#include "cir_queue.h"

cir_queue CirQueueInit(int num_elem)
{
	cir_queue pqueue = (cir_queue) malloc(sizeof(struct cir_queue_s));
	if (!pqueue) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}

	pqueue->num_elem = num_elem;
	pqueue->front = 0;
	pqueue->rear = 0;
	//leave the last element as a symbol to judge the queue is full or empty, and the element don't storage data.
	pqueue->elem = (cir_queue_elemtype*) malloc(sizeof(cir_queue_elemtype) * (num_elem + 1));
	
	return pqueue;
}

bool CirQueueEmpty(cir_queue queue)
{
	return queue->front == queue->rear;
}

bool CirQueueFull(cir_queue queue)
{
	return (queue->rear + 1) % queue->num_elem == queue->front;
}

bool CirQueueEnter(cir_queue queue, cir_queue_elemtype elem)
{
	if (CirQueueFull(queue)) {
		printf("Full queue.\n");
		return false;
	}

	queue->elem[queue->rear++] = elem;
	return true;
}

cir_queue_elemtype CirQueueExit(cir_queue queue)
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
