#ifndef CIR_QUEUE_H
#define CIR_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ELEM 100

typedef int elem_type;
typedef struct queue {
	int front;
	int count;
	elem_type * elem;
} *cir_queue;

/********************************
* aim:       create a new circularly queue and initialize it.
* parameter: void.
* return:    the new circularly queue.
********************************/
cir_queue CirQueueInit(void);

/********************************
* aim:       judge a queue is empty or not.
* parameter: queue: the queue.
* return:    a bool value whether the squeue is empty or not.
********************************/
bool CirQueueEmpty(cir_queue queue);

/********************************
* aim:       judge a queue is full or not.
* parameter: queue: the queue.
* return:    a bool value whether the queue is full or not.
********************************/
bool CirQueueFull(cir_queue queue);

/********************************
* aim:       make a element enter into the queue.
* parameter: queue: the queue.
*            elem:  the element.
* return:    a bool value whether the operator is success or not.
********************************/
bool CirQueueEnter(cir_queue queue, elem_type elem);

/********************************
* aim:       make a element out of the queue.
* parameter: queue: the queue.
* return:    the value of the element which will be exited.
********************************/
elem_type CirStackExit(cir_queue queue);

/********************************
* aim:       clear a queue.
* parameter: queue: the queue.
* return:    void.
********************************/
void CirQueueClear(cir_queue queue);

/********************************
* aim:       destroy a queue.
* parameter: stack: a pointer to the queue.
* return:    void.
********************************/
void CirQueueDestroy(cir_queue * queue);

#endif
