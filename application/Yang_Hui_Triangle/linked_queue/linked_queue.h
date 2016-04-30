#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int linked_queue_elemtype;
typedef struct linked_queue_s {
	struct linked_queue_node_s * first;
	struct linked_queue_node_s * rear;
} *linked_queue;

typedef struct linked_queue_node_s {
	linked_queue_elemtype elem;
	struct linked_queue_node_s * next;
}*linked_queue_node;

/********************************
* aim:       create a new linked queue and initialize it.
* parameter: void.
* return:    the new linked queue.
********************************/
linked_queue LinkedQueueInit(void);

/********************************
* aim:       judge a queue is empty or not.
* parameter: queue: the queue.
* return:    a bool value whether the squeue is empty or not.
********************************/
bool LinkedQueueEmpty(linked_queue queue);

/********************************
* aim:       make a element enter into the queue.
* parameter: queue: the queue.
*            elem:  the element.
* return:    void
********************************/
void LinkedQueueEnter(linked_queue queue, linked_queue_elemtype elem);

/********************************
* aim:       make a element out of the queue.
* parameter: queue: the queue.
* return:    the value of the element which will be exited.
********************************/
linked_queue_elemtype LinkedQueueExit(linked_queue queue);

/********************************
* aim:       destroy a queue.
* parameter: stack: a pointer to the queue.
* return:    void.
********************************/
void LinkedQueueDestroy(linked_queue * queue);

#endif
