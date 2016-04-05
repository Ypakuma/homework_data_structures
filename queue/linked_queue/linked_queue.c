#include "linked_queue.h"

linked_queue LinkedQueueInit(void)
{
	linked_queue pqueue = (linked_queue) malloc(sizeof(struct linked_queue_s));
	//linked_queue_node pnode = (linked_queue_node) malloc(sizeof(struct queue_node));

	pqueue->first = NULL;
	pqueue->rear = NULL;
	//pnode->next = NULL;
}

bool LinkedQueueEmpty(linked_queue queue)
{
	return !(queue->first && queue->rear);
}

void LinkedQueueEnter(linked_queue queue, linked_queue_elemtype elem)
{
	linked_queue_node pnode = (linked_queue_node) malloc(sizeof(struct linked_queue_node_s));

	if (LinkedQueueEmpty(queue)) {
		queue->first = pnode;
		queue->rear = pnode;
		pnode->elem = elem;
		pnode->next = NULL;
		return;
	}

	pnode->elem = elem;
	pnode->next = NULL;
	queue->rear->next = pnode;
	queue->rear = pnode;
}

linked_queue_elemtype LinkedQueueExit(linked_queue queue)
{
	if (LinkedQueueEmpty(queue)) {
		printf("Empty queue.\n");
		exit(0);
	}

	linked_queue_node pnode = queue->first;
	linked_queue_elemtype elem = pnode->elem;
	queue->first = queue->first->next;
	free(pnode);
	return elem;
}

void LinkedQueueDestroy(linked_queue * queue)
{
	if (LinkedQueueEmpty(*queue))
		return;
	while (!LinkedQueueEmpty(*queue)) {
		linked_queue_node pnode = (*queue)->first;
		(*queue)->first = pnode->next;
		free(pnode);
	}
	free(*queue);
	(*queue) = NULL;
}
