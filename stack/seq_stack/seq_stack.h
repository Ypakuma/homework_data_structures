#ifndef SEQ_STACK_H
#define SEQ_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ELEM_SEQ_STACK 100

typedef int seq_stack_elemtype;
typedef struct seq_stack_s{
	int top;
	int len;
	seq_stack_elemtype * elem;
} *seq_stack;

/********************************
* aim:       create a new sequential stack and initialize it.
* parameter: void.
* return:    the new sequential stack.
********************************/
seq_stack SeqStackInit(void);

/********************************
* aim:       judge a stack is empty or not.
* parameter: stack: the stack.
* return:    a bool value whether the stack is empty or not.
********************************/
bool SeqStackEmpty(seq_stack stack);

/********************************
* aim:       judge a stack is full or not.
* parameter: stack: the stack.
* return:    a bool value whether the stack is full or not.
********************************/
bool SeqStackFull(seq_stack stack);

/********************************
* aim:       push a element into the stack.
* parameter: stack: the stack.
*            elem:  the element.
* return:    a bool value whether the operator is success or not.
********************************/
bool SeqStackPush(seq_stack stack, seq_stack_elemtype elem);

/********************************
* aim:       pop a element out of the stack.
* parameter: stack: the stack.
* return:    the value of the element which will be poped.
********************************/
seq_stack_elemtype SeqStackPop(seq_stack stack);

/********************************
* aim:       clear a stack.
* parameter: stack: the stack.
* return:    void.
********************************/
void SeqStackClear(seq_stack stack);

/********************************
* aim:       destroy a stack.
* parameter: stack: a pointer to the stack.
* return:    void.
********************************/
void SeqStackDestroy(seq_stack * stack);

#endif