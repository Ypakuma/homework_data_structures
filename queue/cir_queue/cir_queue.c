#include "cir_queue.h"

seq_queue SeqQueueInit(void)
{
	seq_queue pqueue = (seq_queue) malloc(sizeof(struct queue));

	pqueue->front = 0;
	pqueue->count = 0;
	pqueue->elem = (elem_type*) malloc(sizeof(elem_type) * MAX_ELEM);
	
	return pqueue;
}

bool SeqQueueEmpty(seq_queue queue)
{
	return !(queue->count);
}

bool SeqQueueFull(seq_queue queue)
{
	return queue->count == MAX_ELEM;
}

bool SeqQueueEnter(seq_queue queue, elem_type elem)
{
	if (SeqQueueFull(queue)) {
		printf("Full queue.\n");
		return false;
	}

	int index = (queue->front + queue->count) % MAX_ELEM;
	queue->elem[index] = elem;
	queue->count++;
	return true;
}

elem_type SeqStackExit(seq_queue queue)
{
	if (SeqStackEmpty(queue)) {
		printf("Empty queue.\n");
		exit(0);
	}

	queue->count--;
	elem_type elem =  queue->elem[queue->front];
	queue->front = (queue->front + 1) % MAX_ELEM;

	return elem;
}

void SeqQueueClear(seq_queue queue)
{
	queue->front = 0;
	queue->count = 0;
}

void SeqQueueDestroy(seq_queue * queue)
{
	if (*queue) {
		free((*queue)->elem);
		free(*queue);
		(*queue) = NULL;
	}
}
